#include<cstdio>
#define ll long long
const ll md=1e9+7;

ll fac[150055];

void faccalc()
{
    fac[1]=1;
    for(ll i=2;i<=100186;i++)
    {
        fac[i]=(fac[i-1]*i)%md;
    }
}

ll fsmod(ll a,ll b)
{
    if(b==0) return 1;
    ll ans=1;
    a%=md;
    while(b)
    {
        if(b&1) ans=(a*ans)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return ans;
}

ll whatisthisfuckingfunctiondoing(ll a,ll mod) //WhyNotDefine???
{
    return fsmod(a,mod-2);
}

ll _C(ll n,ll m)
{
    if(n==m||m==0||n==0) return 1;
    ll a=fac[n];
    ll b=(fac[m]*fac[n-m])%md;
    return (a*whatisthisfuckingfunctiondoing(b,md))%md;
}

int main()
{
    ll n,k;
    faccalc();
    scanf("%lld %lld",&n,&k);
    ll ans=fsmod(k,n);
    ll p=-1;
    for(ll i=1;i<=k;i++)
    {
        ans+=p*_C(k,i)*fsmod(k-1,n);
        ans%=md;
        p*=-1;
    }
    printf("%lld\n",(ans%md+md)%md);
    return 0;
}
