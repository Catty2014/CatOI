#include <cstdio>

typedef long long ll;
ll M=1,ans=0;
int n,a[13],b[13];

int Exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    ll ret=Exgcd(b,a%b,x,y);
    ll t=x;
    x=y;y=t-a/b*y;
    return ret;
}

void crt()
{
    ll Mi,x,y,d;
    for(int i=1;i<=n;i++)
    {
        Mi=M/a[i];
        d=Exgcd(Mi,a[i],x,y);
        ans=((ans+Mi*x*b[i])%M+M)%M;
    }   
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        M*=a[i];
    }
    crt();
    printf("%lld",ans);
}