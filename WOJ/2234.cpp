/****************************************
 * Partial Version
 ****************************************/
#include <cstdio>

typedef long long ll;

ll fMod(ll a,ll b,ll m)
{
    ll r=1;
    while(b)
    {
        if(b&1) r=r*a%m;
        a=a*a%m;
        b>>=1;
    }
    return r;
}

int main()
{
    int t,k;
    scanf("%d %d",&t,&k);
    if(k>=2) return 1;
    for(int i=1;i<=t;i++)
    {
        ll y,z,p;
        scanf("%lld %lld %lld",&y,&z,&p);
        printf("%lld\n",fMod(y,z,p));
    }
}
