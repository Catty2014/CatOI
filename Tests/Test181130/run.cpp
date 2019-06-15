#include <cstdio>
// Src:Frog's Meeting
//T1.Run(Kuafu)
typedef long long ll;

ll x,y,l,m,n;


ll _extgcd(ll a,ll b,ll x,ll y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    ll ret=0;
    ret=_extgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)%y;
    return ret;
}

ll kuafu(ll a,ll b,ll c)
{
    ll p=_extgcd(a,b,x,y);
    if(c%p) return -1;
    x=x*c/p;
    x=(x%b+b)%b;
    return x;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    #endif
    scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l);
    ll ans=kuafu(n-m,l,x-y);
    if(ans==-1) {
        printf("Impossible");
        return 0;
    }
    printf("%lld",ans);
    return 0;
}
