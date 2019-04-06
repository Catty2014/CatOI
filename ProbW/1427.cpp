/*
//Mtd:FORCE
#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) prlong longf("var=%d\n",x)

using namespace std;

long long main()
{
    long long p,b,k;
    scanf("%lld %lld %lld",&b,&p,&k);
    long long ans=1;
    for(long long i=1;i<=p;i++)
    {
        ans*=b;
        ans%=k;
    }
    prlong longf("%lld^%lld mod %lld=%lld",b,p,k,ans%k);
    return 0;
}
*/
#include <cstdio>

int main()
{
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    long long ora=1;
    long long orb=b;
    long long t=a;
    while(b)
    {
        if(b&1) ora*=t;
        ora%=p;
        t*=t;
        t=t%p;
        b>>=1;
        /* printf("%lld\n",ora); */
    }
    printf("%lld^%lld mod %lld=%lld\n",a,orb,p,ora);
}
