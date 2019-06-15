#include<cstdio>
#define LL long long
const int N=100086;
const int MOD=1e9+7;

LL f[N]={0};
LL fastmul(LL p,LL q,LL mod) // FastMulAndMod (p^q)%mod
{
    if(q==0) return 1; 
    LL ans=1;
    while(q)
    {
        if(q&1) ans=p*ans%mod;
        p=p*p%mod;
        q>>=1;
    }
    return ans%mod;
}
LL cal(LL n,LL m)
{
    return f[n]*fastmul(f[m],MOD-2,MOD)%MOD*fastmul(f[n-m],MOD-2,MOD)%MOD;
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
            f[i]=f[i-1]*i%MOD; //PreloadFac
    }
    printf("%lld\n",cal(n,m));
    return 0;
}