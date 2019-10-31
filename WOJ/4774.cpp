#include "cstdio"
#include "algorithm"
#include <bits/stdc++.h>
#include <bits/extc++.h>

typedef long long ll;

/* #define swap(x,y) {x^=y,y^=x,x^=y;} */
/* #define min(x,y) ((x<y)?x:y) */
/* #define abs(x) ((x<0)?(-x):x) */
using std::abs;
using std::min;

void Xgcd(ll a,ll b,ll m,ll &x,ll &y)
{
    if(b==0)
    {
        x=m/a;
        y=0;
        return;
    }
    Xgcd(b,a%b,m,x,y);
    std::swap(x,y);
    y-=a/b*x;
}

ll gcd(int a,int b)
{
        return (b==0)?a:gcd(b,a%b);
}

ll n,a,b;
ll k;
ll x,y,p;


int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%lld %lld %lld",&n,&a,&b);
    k=gcd(a,b);
    a/=k;
    b/=k;
    if(a<b) std::swap(a,b);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t%k)
        {
            printf("%d\n",-1);
            return 0x00;
        }
        Xgcd(a,b,t/k,x,y);
        if(y<0)
        {
            x-=b*((-y)/a+1);
            y+=a*((-y)/a+1);
        }
        x+=b*(y/a);
        y-=a*(y/a);
        p+=min(abs(x)+abs(y),abs(x+b)+abs(y-a));
    }
    printf("%lld",p);
    return 0;
}
