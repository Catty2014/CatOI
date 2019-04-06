#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 100860
#define lc (p<<1)
#define rc (p<<1|1)
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct SmTree
{
    int l,r,lz[2];
    int w[2];
}a[M<<2];

int n,q,last=0;
void pushnow(int p,int k,int d)
{
    a[p].w[d]+=(a[p].r-a[p].l+1)*k;
    a[p].lz[d]+=k;
}

void pushup(int p)
{
    a[p].w[0]=a[lc].w[0]+a[rc].w[0];
    a[p].w[1]=a[lc].w[1]+a[rc].w[1];
}

void pushdown(int p)
{
    for(int i=0;i<2;i++)
    {
        if(a[p].lz[i])
        {
            pushnow(lc,a[p].lz[i],i);
            pushnow(rc,a[p].lz[i],i);
            a[p].lz[i]=0;
        }
    }
}

void build(int p,int l,int r)
{
    a[p].l=l;a[p].r=r;
    if(l==r)
    {
        a[p].w[0]=a[p].w[1]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void update(int p,int ql,int qr,int x,int d)
{
    if(qr<a[p].l||ql>a[p].r) return;
    if(ql<=a[p].l&&a[p].r<qr)
    {
        pushnow(p,x,d);
    }
    else
    {
        int mid=(a[p].l+a[p].r)>>1;
        pushdown(p);
        if(ql<=mid) update(lc,ql,qr,x,d);
        if(qr>mid) update(rc,ql,qr,x,d);
        pushup(p);
    }
}

int query(int p,int ql,int qr,int d)
{
    if(qr<a[p].l||ql>a[p].r) return 0;
    if(ql<=a[p].l&&a[p].r<=qr)
    {
        return a[p].w[d];
    }
    else
    {
        int ans=0;
        int mid=(a[p].l+a[p].r)>>1;
        pushdown(p);
        if(ql<=mid) ans+=query(lc,ql,qr,d);
        if(qr>mid) ans+=query(rc,ql,qr,d);
        pushup(p);
        return ans;
    }
}
int main()
{
    scanf("%d %d",&n,&q);
    build(1,1,n);
    while(q--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
        {
            last++;
            update(1,y,y,1,1);
            update(1,x,x,1,0);
        }
        else
        {
            printf("%d\n",last-query(1,1,x-1,1)-query(1,y+1,n,0));
        }
    }
    return 0;
}

