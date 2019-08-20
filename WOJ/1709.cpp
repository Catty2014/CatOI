#include <cstdio>
#include <cmath>
using std::abs;

typedef unsigned int uint;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

void write_t(ll k,ll b) 
{
    /* printf("b=%lld k=%lld\n",b,k); */
    if(k/abs(k)*b>0) printf("-");
    k=abs(k);
    b=abs(b);
    if(b%k==0&&b!=k)
    {
        printf("%lld",b/k);
    }
    if(b%k!=0)
    {
        ll g=gcd(k,b);
        printf("%lld/%lld",b/g,k/g);
    }
    return ;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    ll xa,xb,ya,yb;
    while(scanf("%lld %lld %lld %lld",&xa,&ya,&xb,&yb)!=-1)
    {
        if(xa==xb||ya==yb) 
        {
            printf("Error\n");
            continue;
        }
        ll b=(ya==0)?yb:ya;
        printf("y=");
        write_t((xa==0)?xb:xa,b);
        printf("x");
        if(b==0)
        {
            printf("\n");
            continue;
        }
        printf("%c%lld\n",(b>0)?'+':'-',abs(b));
    }
    return 0;
}
