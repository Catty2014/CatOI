#include <cstdio>

typedef long long ll;
ll n;
ll c[233333],a[233333];

inline ll lbit(ll k)
{
    return k&(-k);
}

inline void add (ll k,ll x)
{
    while(k<=100001)
    {
        c[k]+=x;
        k+=lbit(k);
    }
    return ;        
}

inline ll qur(ll k)
{
    ll ans=0ll;
    while(k)
    {
        ans+=c[k];
        k-=lbit(k);
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    ll sum=0;
    for(ll i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum+=qur(100001)-qur(a[i]);
        add(a[i],1ll);
    }
    printf("%lld\n",sum);
    return 0;
}
