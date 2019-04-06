#include <bits/stdc++.h> //Code of Pig2014
using namespace std;//Contact me:18111431031@163.com
#define debug(x) printf("var=%d\n",x)//Language:Cpp
typedef long long ll;
const int MOD=1e9+7;
const ll ExtremeMod=9e18;
int n;
ll c[55]={1,1,2,0};


ll fsmod(ll b,ll p)
{
    ll ans=1;
    b%=ExtremeMod;
    while(p)
    {
        if(p&1) ans=ans*b%MOD;
        p>>=1;
        b=b*b%MOD;
    }
    return ans;
}

ll inv (ll x)
{
    return fsmod(x,MOD-2);
}
int main()
{
    scanf("%d",&n);
    n-=2;
    for(int i=3;i<=n;i++)
    {
       // c[i]=c[i-1]*(4*i-2)%MOD*inv(i+1);//CatalanNum
        c[i]=(c[i-1]*(4*i-2)%MOD*inv(i+1))%MOD;//CatalanNum
    }
    printf("%lld",c[n]);
    /* for(int i=1;i<=50;i++) */
    /* { */
    /*     printf("%lld\n",c[i]); */
    /* } */
    return 0;
}

