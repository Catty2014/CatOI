#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define lc (k<<1)
#define rc (k<<1|1)
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct SmTree
{
    int l,r,w;
}a[402333];

void BdTree(int k,int l,int r)   //BuildTree
{
    a[k].l=l;a[k].r=r;
    if(l==r)
    {
        a[k].w=0;
        return;
    }
    int mid=(l+r)>>1;
    BdTree(lc,l,mid);
    BdTree(rc,mid+1,r);
    a[k].w=a[lc].w+a[rc].w;
}

void PtEdit(int k,int p,int v)   //PointEdit
{
    if(a[k].l==a[k].r)
    {
        a[k].w+=v;
        return;
    }
    int mid=(a[k].l+a[k].r)>>1;
    if(p<=mid)
        PtEdit(lc,p,v);
    else
        PtEdit(rc,p,v);
    a[k].w=a[lc].w+a[rc].w;
}

int Query(int k,int ql,int qr)   //Query
{
    if(ql<=a[k].l&&qr>=a[k].r)
    {
        return a[k].w;
    }
    int mid=(a[k].l+a[k].r)>>1;
    int ans=0;
    if(ql<=mid) ans+=Query(lc,ql,qr);
    if(qr>mid) ans+=Query(rc,ql,qr);
    return ans;
}

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    BdTree(1,1,n);
    printf("Entered!\n");
    for(int i=1;i<=m;i++)
    {
        int x,y;
        char op;
        cin>>op>>x>>y;
        if(op=='C') PtEdit(1,x,y);
        else
        {
            printf("%d\n",Query(1,x,y));
        }
    }
    return 0;
}

