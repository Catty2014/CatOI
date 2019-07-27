#include <cstdio>
#include <algorithm>

const int N=233333;
typedef const int cint;
typedef long long ll;
int n,k;
int v[N];
ll val[N];
int cnt;
int q[N];
ll d[N];
int cn;
ll mx[N];
int f[N];
int son[N];
struct Edg
{
    int nx,t;
}e[N*2];
int h[N];

bool cmp(cint a,cint b)
{
    return val[a]>val[b];
}

void add(int u,int v)
{
    cnt++;
    e[cnt].t=v;
    e[cnt].nx=h[u];
    h[u]=cnt;
}

void dfs(int x,int fa)
{
    d[x]=d[fa]+v[x];
    f[x]=fa;
    mx[x]=d[x];
    for(int i=h[x];i;i=e[i].nx)
    {
        if(e[i].t!=f[x])
        {
            dfs(e[i].t,x);
            mx[x]=std::max(mx[x],mx[e[i].t]);
            if(mx[e[i].t]>mx[son[x]])
            {
                son[x]=e[i].t;
            }
        }
    }
}

void DFS(int x,int t)
{
    val[t]+=v[x];
    if(son[x])
    {
        DFS(son[x],t);
    }
    for(int i=h[x];i;i=e[i].nx)
    {
        int to=e[i].t;
        if(to!=son[x] && to!=f[x])
        {
            q[++cn]=to;
            DFS(to,to);
        }
    }

}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    q[++cn]=1;
    DFS(1,1);
    std::sort(q+1,q+cn+1,cmp);
    ll ans=0;
    for(int i=1;i<=k;i++)
    {
        ans+=val[q[i]];
    }
    printf("%lld\n",ans);
    return 0;
}
