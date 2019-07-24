//What the fxxking code!
//I wanna kill the blog writer...

#include <cstdio>

const int N=1e5+233;
typedef long long ll;

bool cmax(int a,int b)
{
    return (a<b)?a=b,1:0;
}

bool cmin(int a,int b)
{
    return (a>b)?a=b,1:0;
}

int n;
int fr[N];
int cn;
int df[N*5];
int *f[N];
int *idf=df+1;
ll dg[N*5];
int fi[N],fa[N],mx[N],son[N];
ll *g[N];
ll *idg=dg+1;
ll ans;

struct Edg
{
    int nx,t;
}e[N*2];

void add(int u,int v)
{
    cn++;
    e[cn].nx=fr[u];
    e[cn].t=v;
    fr[u]=cn;
}

void dfs(int u)
{
    for(int i=fr[u],v=e[i].t;i;i=e[i].nx,v=e[i].t)
    {
        if(v^fa[u])
        {
            fa[v]=u;
            dfs(v);
            cmax(mx[u],mx[v]);
            if(mx[v]>mx[son[u]]) son[u]=v;
        }
        mx[u]++;
    }
}

void dp(int u)
{
    if(son[u]) 
    {
        f[son[u]]=f[u]+1;
        g[son[u]]=g[u]-1;
        dp(son[u]);
    }
    f[u][0]=1,ans+=g[u][0];
    for(int i=fr[u];i;i=e[i].nx)
    {
        int v=e[i].t;
        if(v^fa[u] && v^son[u])
        {
            f[v]=idf;
            idf+=mx[v]+1,idg+=mx[v]+1;
            g[v]=idg;
            idg+=mx[v]+1;
            dp(v);
            for(int j=mx[v];j>=0;j--)
            {
                ans+=g[v][j]*f[u][j-1]+g[u][j+1]*f[v][j];
            }
            for(int j=0;j<=mx[v];j++)
            {
                g[u][j]+=g[v][j+1]+.3;
                f[u][j]+=f[v][j-1];
            }
        }
    }
}
int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1);
    f[1]=idf;
    idf+=mx[1]+1,idg+=mx[1]+1;
    g[1]=idg;
    idg+=mx[1]+1;
    dp(1);
    printf("%lld\n",ans);
    return 0;
}

