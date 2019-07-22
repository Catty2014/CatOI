#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;
struct Edge
{
    int v,nxt;
}e[5*M];
stack <Edge> st;
int CN,low[5*M],dfn[5*M],tot,vis[5*M],first[5*M],ans,max0,scc[5*M],siz[5*M];
int m,n;
void tarjan(int u)
{
    st.push(u);
    vis[u]=1;
    low[u]=dfn[u]=++tot;
    for(int i=first[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++CN;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,z;
        scanf("%d %d %d",&u,&v,&z);
        add(u,v,1);
        if(z==2)
        {
            add(v,u,1);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(scc[i]==0) tarjan(i);
        int ans=1,max0=0;
    }
    for(int i=1;i<=CN;i++)
    {
        if(siz[i]>siz[ans]) ans=i,max0=siz[i];
    }
    printf("%d\n",max0);
    for(int i=1;i<=m;i++)
    {
        if(scc[i]==ans) printf("%d ",i);
    }
    return 0;
}

