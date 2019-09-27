#include <cstdio>
#include <cstdlib>
#include <ctime>
typedef long long ll;
typedef unsigned int uint;

uint genRand(uint l,uint r)
{
    static uint x=rand();
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    return x%(r-l+1)+l;
}

ll mul(ll a,ll b,ll M)
{
    ll r=0;
    while(b)
    {
        if(b&1) r=(r+a)%M;
        a=(a+a)%M;
        b>>=1;
    }
    return r;
}

ll pow(ll a,ll p,ll M)
{
    ll r=1;
    while(p)
    {
        if(p&1) r=mul(r,a,M);
        a=mul(a,a,M);
        p>>=1;
    }
    return r;
}

bool millerRabin(int n,int t)
{
    if(n==2) return 1;
    if(n<2||!(n&1)) return 0;
    ll m=n-1,k=0;
    while(!(m&1))
    {
        k++;
        m>>=1;
    }
    for(int i=1;i<=t;i++)
    {
        ll a=genRand(1,n);
        ll x=pow(a,m,n);
        ll y;
        for(int j=1;j<=k;j++)
        {
            y=mul(x,x,n);
            if(y==1&&x!=1&&x!=n-1)
            {
                return 0;
            }
            x=y;
        }
        if(y!=1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll t;
        scanf("%lld",&t);
        printf("%s\n",millerRabin(t,10)?"yes":"no");
    }
    return 0;
}
