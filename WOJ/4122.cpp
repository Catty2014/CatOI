#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

const int N=233333;

typedef long long ll;
struct Edg
{
    ll u,v,s;
    bool operator < (const Edg &a) const{
        return s<a.s;
    }
}e[N*2];

ll ans=0x6666666666666666;
ll sum;
ll f[N];
ll fa[N],num[N],mx[N],mn[N],u[N],v[N],s[N];

int n,m;

int ffa(int x)
{
    return (fa[x]==x)?x:ffa(fa[x]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        scanf("%lld %lld",&mx[i],&mn[i]);
        sum+=(f[i]=(ll)mx[i]*mn[i]);
    }   
    for(int i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].s);
    } 
    ans=min(ans,sum);
    std::sort(e+1,e+m+1);
    for(int i=1;i<=m;i++)
    {
        int faa=ffa(e[i].u);
        int fbb=ffa(e[i].v);
        if(faa==fbb) continue;
        f[faa]+=f[fbb];
        sum-=f[faa];
        mn[faa]=min(mn[faa],mn[fbb]);
        mx[faa]=max(mx[faa],mx[fbb]);
        mx[faa]=max(mx[faa],e[i].s);
        sum+=(f[faa]=min(f[faa],mx[faa]*mn[faa]));
        f[fbb]=faa;
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}