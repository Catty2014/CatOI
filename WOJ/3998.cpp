#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=1e6+2333;
typedef long long ll;
typedef double db;

ll n;
ll a[N];
ll dp[N];
ll q[N];

db slp(ll k,ll j)
{
    return 1.0*(dp[k]-dp[j]+(k*k+k-j-j*j)/2)/(k-j);
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ll k,l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        while(l<r&&slp(q[l],q[l+1])<i)l++;
        k=q[l];
        dp[i]=dp[k]+a[i]+(i-k)*(i-k-1)/2;
        while(l<r&&(slp(q[r],i)<slp(q[r-1],q[r]))) r--;
        q[++r]=i;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
