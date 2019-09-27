#include <cstdio>

const int N=200233;

struct Edge
{
    int u,v,n;
}e[N];
int vi[N];
int h[N];
int eCnt;

void add(int u,int v)
{
    eCnt++;
    e[eCnt].u=u;
    e[eCnt].v=v;
    e[eCnt].n=h[u];
    h[u]=eCnt;
}

void dfs(int u)
{
    if(vi[u]) return;
    vi[u]=1;
    printf("%d\n",u);
    for(int i=h[u];i;i=e[i].n)
    {
        dfs(e[i].v);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        int v;
        scanf("%d %d %d",&x,&y,&v);
        add(x,y);
        add(y,x);
    }
    dfs(1);
    return 0;
}
