//Chairman Tree Template
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;//not suggested

#define ls l,m
#define rs m+1,r
const int N=100233;
int L[N<<5],R[N<<5],sum[N<<5];
int t;
int a[N],T[N],HS[N];

int build(int l,int r)
{
    int rt=(++t);
    sum[rt]=0;
    if(l<r)
    {
        int m=(l+r)>>1;
        L[rt]=build(ls);
        R[rt]=build(rs);
    }
    return rt;
}

int upd(int pre,int l,int r,int x)
{
    int rt=++t;
    L[rt]=L[pre],R[rt]=R[pre],sum[rt]=sum[pre]+1;
    if(l<r)
    {
        int m=(l+r)>>1;  //mid
        if(x<=m)
        {
            L[rt]=upd(L[pre],ls,x);
        }
        else
        {
            R[rt]=upd(R[pre],rs,x);
        }
        
    }
    return rt;
}

int qur(int u,int v,int l,int r,int k)
{
    if(l>=r) return l;
    int m=(l+r)>>1;
    int num=sum[L[v]]-sum[L[u]];
    if(num>=k)
    {
        return qur(L[u],L[v],ls,k);
    }
    else
    {
        return qur(R[u],R[v],rs,k-num);
    }
}

int main()
{
    t=0;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        HS[i]=a[i];
    }
    sort(HS+1,HS+n+1);
    int d=unique(HS+1,HS+n+1)-HS-1;
    T[0]=build(1,d);
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(HS+1,HS+d+1,a[i])-HS;
        T[i]=upd(T[i-1],1,d,x);
    }
    while(m--)
    {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        int x=qur(T[l-1],T[r],1,d,k);
        printf("%d\n",HS[x]);
    }
    return 0;
}