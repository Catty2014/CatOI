//Tree:OK
//Ringed tree:attempting...
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int N=100333;
struct Edge
{
    int u,v,n;
    int d;
}e[N];
int f[N],cntE;
int ans[N],tmp[N],vis[N];
int tg;
int n,m;

void addEdge(int u,int v)
{
    cntE++;
    e[cntE].u=u;
    e[cntE].v=v;
    e[cntE].n=f[u];
    f[u]=cntE;
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
        addEdge(u,v);
        addEdge(v,u);
    }
    if(n==m)//基环树
    {

        /* printf("%d\n",n); */
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
