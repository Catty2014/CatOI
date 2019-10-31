//Tree:OK
//Ringed tree:attempting...
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int N=100333;
struct Edge
{
    int u,v,n,p;
    int d;
}e[N];
int f[N],cntE;
int ans[N],tmp[N],vis[N];
int tg;
int n,m;
int fa[N];
int loop[N];
int cntL;

void addEdge(int u,int v,int c)
{
    cntE++;
    e[cntE].u=u;
    e[cntE].v=v;
    e[cntE].n=f[u];
    f[u]=cntE;
    if(c==1) e[cntE].p=cntE+1;
    else e[cntE].p=cntE-1;
    if(c==1) addEdge(v,u,0);
}

int tms=0;
void getloop(int u)
{
    vis[u]=++tms;
    for(int i=f[u];i;i=e[i].n)
    {
        int v=e[i].v;
        if(v==fa[v]) continue;
        if(vis[v])
        {
            if(vis[v]<vis[u]) continue;
            for(int i=f[v];i;i=e[i].n)
            {
                if(e[i].v==fa[v])
                {
                    loop[++cntL]=i;
                    loop[++cntL]=e[i].p;
                    break;
                }
            }
            v=fa[v];
            while(v!=fa[u])
            {
                for(int i=f[v];i;i=e[i].n)
                {
                    if(e[i].v==fa[v])
                    {
                        loop[++cntL]=i;
                        loop[++cntL]=e[i].p;
                        break;
                    }
                }
                v=fa[v];
            }
        }
        else fa[v]=u,getloop(v);
    }
    
}

void update()
{
    int mrk=0;
    for(int i=1;i<=n;i++)
    {
        if(tmp[i]<ans[i]||ans[i]==0) 
        {
            mrk=1;
        }
        if(mrk==1)
        {
            ans[i]=tmp[i];
        }
    }
    return ;
}

void dfs(int u)
{
    tmp[++tg]=u;
    int s[200],h=0;
    for(int i=f[u];i;i=e[i].n)
    {
        int v=e[i].v;
        if(e[i].d==1||vis[v]==1) continue;
        s[++h]=v;
    }
    std::sort(s+1,s+h+1);
    for(int i=1;i<=h;i++)
    {
        vis[s[i]]=1;
        dfs(s[i]);
        vis[s[i]]=0;
    }
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(u,v,1);
    }
    if(n==m)//基环树
    {
        getloop(1);
        for(int i=1;i<=cntL-1;i+=2)
        {
            e[loop[i]].d=1;
            e[loop[i+1]].d=1;
            dfs(1);
            update();
            e[loop[i]].d=0;
            e[loop[i+1]].d=0;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
        return 0;
    }
    else
    {
        vis[1]=1;
        dfs(1);
        update();
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
    return 0;
}
