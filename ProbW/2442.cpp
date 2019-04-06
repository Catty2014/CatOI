#include <cstdio>
#include <algorithm>
#include <cmath>

typedef long long ll;
using std::sqrt;
using std::min;

ll m,n;
ll k;
ll idx[233333],v[233333],sum[233333],f[233333];

void _sol(int id)
{
    if(f[id]) return ;
    f[id]=1;
    sum[id]=0;
    for(int i=(id-1)*k+1;i<=id*k;i++)
    {
        v[i]=sqrt(v[i]);
        sum[id]+=v[i];
        if(v[i]>1) f[id]=0;
    }
    return ;
}

void _add(ll x,ll y)
{
    for(ll i=x;i<=min((ll)idx[x]*k,y);i++)
    {
        sum[idx[i]]-=v[i];
        v[i]=sqrt(v[i]);
        sum[idx[i]]+=v[i];
    }
    if(idx[x]!=idx[y])
    {
        for(ll i=(idx[y]-1)*k+1;i<=y;i++)
        {
            sum[idx[i]]-=v[i];
            v[i]=sqrt(v[i]);
            sum[idx[i]]+=v[i];
        }
    }
    for(ll i=idx[x]+1;i<=idx[y]-1;i++)
    {
        _sol(i);
    }
}

ll _qur(ll x,ll y)
{
    ll ans=0;
    for(ll i=x;i<=min(idx[x]*k,y);i++)
    {
        ans+=v[i];
    }
    if(idx[x]!=idx[y])
    {
        for(ll i=(idx[y]-1)*k+1;i<=y;i++)
        {
            ans+=v[i];
        }
    }
    for(ll i=idx[x]+1;i<=idx[y]-1;i++)
    {
        ans+=sum[i];
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    k=sqrt(n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        idx[i]=(i-1)/k +1;
        sum[idx[i]]+=v[i];
    }
    scanf("%d",&m);
    while(m--)
    {
        ll op,x,y;
        scanf("%lld %lld %lld",&op,&x,&y);
        if(op==1)
        {
            printf("%lld\n",_qur(x,y));
        }
        if(op==2)
        {
            _add(x,y);
        }

    }        
    return 0;
}