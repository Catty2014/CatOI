#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 60086
#define debug(x) printf("var=%d\n",x)
using namespace std;
struct Edge
{
    int u,v,next;
}e[M];
int cnt,f[M],dfn[M],low[M],tim,siz[M],clr[M],cd[M];
int vst[M];
stack <int> st; 
int m,n;
int scc;
void add(int u,int v)
{
    cnt++;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].next=f[u];
    f[u]=cnt;
}

void tj(int u)
{
    dfn[u]=low[u]=++tim;
    st.push(u);
    vst[u]=1;
    for(int i=f[u];i;i=e[i].next)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tj(v);
            low[u]=min(low[u],low[v]);
        }
        else if (vst[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int t;
        ++scc;
        do
        {
            t=st.top();
            st.pop();
            vst[t]=0;
            clr[t]=scc;
            siz[scc]++;
        }while(t!=u);
    }
}
int main()
{
    cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tj(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(clr[e[i].u]!=clr[e[i].v])
            cd[clr[e[i].u]]++;
    }
    int ans=0;
    for(int i=1;i<=scc;i++)
    {
        if(cd[i]==0)
        {
            if(ans)
            {
                ans=0;
                break;
            }
            ans=i;
        }
    }
    printf("%d",siz[ans]);
    return 0;
}

