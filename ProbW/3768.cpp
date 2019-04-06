#include <bits/stdc++.h>
using namespace std;
#define N 10086

struct  Node
{
    int u,v,w;
}e[N*20];

int first[N]={0},nxt[N*20],cnt=0;
int n,m;
int vis[N]={};

void add (int u,int v,int w)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    nxt[cnt]=first[u];
    first[u]=cnt;
}

void init()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
}

void dfs(int x)
{
    vis[x]=1;
    printf("%d\n",x);
    for(int i=first[x];i;i=nxt[i])
        if(!vis[e[i].v]) dfs(e[i].v);
}
int main()
{
    init();
    dfs(1);
    return 0;
}

