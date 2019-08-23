#include <cstdio>

typedef long long ll;

const int M=100003;

ll fMod(ll a,ll b)
{
    ll r=1;
    while(b)
    {
        if(b&1) r=r*a%M;
        a=a*a%M;
        b>>=1;
    }
    return r;
}

int main(void)
{
    ll n,m;
    scanf("%lld %lld",&m,&n);
    printf("%lld\n",(fMod(m,n)+M-m*fMod(m-1,n-1)%M+M)%M);
    return 0;
}
