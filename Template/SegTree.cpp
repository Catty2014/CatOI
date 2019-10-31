#include <cstdio>

const int N=423333;

class SegTree
{
#define int long long
private:
    int n;
    int a[N];
    int lz[N];
#define ls (p<<1)
#define rs (p<<1|1)
public:
    int b[N/4];
    void pushDown(int p,int ln)
    {
        if(lz[p]==0) return;
        lz[ls]=lz[p];
        lz[rs]=lz[p];
        a[ls]+=lz[ls]*(ln-(ln)/2);
        a[rs]+=lz[rs]*(ln/2);
        /* a[rs]=lz[rs]*(ln-(ln)/2); */
        /* a[ls]=lz[ls]*(ln/2); */
        lz[p]=0;
    }
    void pushUp(int p)
    {
        a[p]=a[ls]+a[rs];
    }
    void build(int l,int r,int p)
    {
        lz[p]=0;
        if(l==r)
        {
            a[p]=b[l];return;
        }
        int m=(l+r)>>1;
        build(l,m,ls);
        build(m+1,r,rs);
        pushUp(p);
    }
    void update(int s,int v,int l,int r,int p)
    {
        if(l==r)
        {
            a[p]+=v;
            return;
        }
        int m=(l+r)>>1;
        if(s>m)
        {
            update(s,v,m+1,r,rs);
        }
        else
        {
            update(s,v,l,m,ls);
        }
        pushUp(p);
    }
    void upgrade(int sl,int sr,int l,int r,int v,int p)
    {
        if(sl<=l&&sr>=r)
        {
            a[p]+=(r-l+1)*v;
            lz[p]+=v;
            return;
        }
        pushDown(p,r-l+1);
        int m=(l+r)>>1;
        if(sl<=m)
        {
            upgrade(sl,sr,l,m,v,ls);
        }
        if(sr>m)
        {
            upgrade(sl,sr,m+1,r,v,rs);
        }
        pushUp(p);
    }
    int query(int sl,int sr,int l,int r,int p)
    {
        if(l>=sl&&r<=sr)
        {
            return a[p];
        }
        pushDown(p,r-l+1);
        int m=(l+r)/2;
        int ans=0;
        if(sl<=m)
        {
            ans+=query(sl,sr,l,m,ls);
        }
        if(sr>m)
        {
            ans+=query(sl,sr,m+1,r,rs);
        }
        return ans;
    }
}s;
#undef int

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s.b[i]);
    }
    s.build(1,n,1);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r,v;
            scanf("%d %d %d",&l,&r,&v);
            s.upgrade(l,r,1,n,v,1);
        }
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",s.query(l,r,1,n,1));
        }
    }
}
