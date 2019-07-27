#include <cstdio>
#include <algorithm>
using std::max;
/* #define max(a,b) ((a>b)?a:b) */

const int N=100233;
#define ls (p<<1)
#define rs (p<<1|1)

struct Node
{
    int l,r;
    int mxv,add;
};

class Smt
{
private:
    Node t[N*5];
public:
    int a[N];
    void pu(Node &d,Node &ld,Node &rd)
    {
        d.mxv=max(ld.mxv,rd.mxv);
    }
    void pd(Node &d,Node &ld,Node &rd)
    {
        ld.add+=d.add;
        ld.mxv+=d.add;
        rd.add+=d.add;
        rd.mxv+=d.add;
        d.add=0;
    }
    void bd(int p,int l,int r)
    {
        t[p].l=l;
        t[p].r=r;
        t[p].add=0;
        if(l==r)
        {
            t[p].mxv=a[l];
            return ;
        }
        int m=(l+r)/2;
        bd(ls,l,m);
        bd(rs,m+1,r);
        pu(t[p],t[ls],t[rs]);
    }
    void upd(int p,int l,int r,int v)
    {
        if(l<=t[p].l&&t[p].r<=r) 
        {
            t[p].add+=v;
            t[p].mxv+=v;
            return ;
        }
        pd(t[p],t[ls],t[rs]);
        int m=(t[p].l+t[p].r)/2;
        if(m>=l) upd(ls,l,r,v);
        if(m<r) upd(rs,l,r,v);
        pu(t[p],t[ls],t[rs]);
    }
    int qur(int p,int l,int r)
    {
        if(l<=t[p].l&&t[p].r<=r) return t[p].mxv;
        pd(t[p],t[ls],t[rs]);
        int ans=0;
        int m=(t[p].l+t[p].r)/2;
        if(m>=l) ans=max(ans,qur(ls,l,r));
        if(m<r) ans=max(ans,qur(rs,l,r));
        pu(t[p],t[ls],t[rs]);
        return ans;
    }
};
Smt t;
int m,n;
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t.a[i]);
    }
    t.bd(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;
        scanf("%d",&op);
        if(op==1) //Modify
        {
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v);
            t.upd(1,x,y,v);
        }
        if(op==2) //Max
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",t.qur(1,x,y));
        }
    }
    return 0;
}
