#include <cstdio>

typedef long long ll;

ll gcdX(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    else
    {
        ll r=gcdX(b,a%b,x,y);
        ll t=x;
        x=y;
        y=t-a/b*y;
        return r;
    }
}

ll gcd(ll a,ll b)
{
    return (b)?gcd(b,a%b):a;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,m,x,y;
        scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
        ll a=m;
        ll b=n;
        ll d=(y-x+n)%n;
        ll p,q;
        ll _gcd=gcdX(a,b,p,q);
        ll r=b/_gcd;
        if(d%_gcd) printf("Impossible\n");
        else printf("%lld\n",(d/_gcd*p%r+r)%r);
    }
    return 0;
}
