#include <cstdio>
#include <vector>
const int N=600233;

typedef long long ll;

struct Edg
{
    int nx,t;
}e[N];

struct Qur
{
    int id,k;
};

int h[N];
int cnt;
int n,Q;
std::vector <Qur> q[N];
int siz[N];
int dis[N];
int dep[N];
int son[N];
ll *f[N];
ll ans[N];
ll tmp[N];
ll *id=tmp;

void add(int u,int v)
{
    cnt++;
    e[cnt].nx=h[u];
    e[cnt].t=v;
    h[u]=cnt;
}

void dfs1(int u,int f)
{
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nx)
    {
        int v=e[i].t;
        if(v==f) continue;
        dis[v]=dis[u]+1;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(dep[v]>dep[son[u]]) son[u]=v;
    }
    dep[u]=dep[son[u]]+1;
}

void dfs2(int u,int fa)
{
    if(son[u])
    {
        f[son[u]]=f[u]+1,dfs2(son[u],u);
    }
    for(int i=h[u];i;i=e[i].nx)
    {
        int v=e[i].t;
        if(v==fa||v==son[u]) continue;
        f[v]=id;
        id+=dep[v];
        dfs2(v,u);
        for(int i=0;i<dep[v];i++)
        {
            f[u][i+1]+=f[v][i];
        }
    }
    for(int i=0;i<(int)q[u].size();i++)
    {
        int k=q[u][i].k;
        int id=q[u][i].id;
        ans[id]+=1ll*(siz[u]-1)*std::min(dis[u],k);
        if(k>=dep[u]-1) ans[id]+=f[u][1];
        else ans[id]+=f[u][1]-f[u][k+1];
    }
    f[u][0]=f[u][1]+siz[u]-1;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=Q;i++)
    {
        int u,k;
        scanf("%d %d",&u,&k);
        q[u].push_back((Qur){i,k});
    }
    dfs1(1,0);
    f[1]=id;
    id+=dep[1];
    dfs2(1,0);
    for(int i=1;i<=Q;i++)
    {
        printf("%lld\n",ans[i]);
    }
}
