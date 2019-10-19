#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=100233;
typedef long long ll;

ll a[N];
ll b[N];
ll c[N];

bool cmp(const int a,const int b)
{
    return a<b;
}
int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        ll l,r;
        scanf("%lld %lld",&l,&r);
        for(int j=l;j<=r;j++)
        {
            b[j-l+1]=a[j];
        }
        std::sort(b+1,b+r-l+2,cmp);
        for(int j=1;j<=r-l+1;j++)
        {
            if(!c[b[j]]) c[b[j]]=j;
        }
        ll ans=0;
        for(int j=l;j<=r;j++)
        {
            ans+=a[j]*c[a[j]];
        }
        printf("%lld\n",ans);
    }
}
