#include <cstdio>
#include <algorithm>

using std::sort;

typedef long long ll;

ll a[252333],cnt;
bool chk(ll x)
{
    for(ll i=1;i<=cnt;i++)
    {
        if(a[i]%x==0) return 0;
    }
    return 1;
}
ll gcd(ll a,ll b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(int argc, char *argv[])
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    ll n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&a[i]);
    }
    ll ans=n;
    for(ll i=1;i<=k;i++)
    {
        a[i]=gcd(n,a[i]);
    }
    sort(a+1,a+k);
    for(ll i=1;i<k;i++)
    {
        if(a[i]!=a[i-1])
        {
            cnt++;
            a[cnt]=a[i];
        }
    }
    for(ll i=1;i*i<=a[k];i++)
    {
        if(a[k]%i==0)
        {
            if(chk(i)) 
            {
                ans=n/i;
                break;
            }
            else if (chk(a[k]/i)) {
                ans=n/a[k]*i;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
