#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 50086
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct Edge
{
    int u,v,next;
}e[M];
int scc,dfn[M],low[M],vst[M];
int fa[M],clr[M];
int cd[M],rd[M];
int cnt,tim;
int siz[M];
stack <int> st;
void add(int u,int v)
{
    cnt++;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].next=fa[u];
    fa[u]=cnt;
}
inline int read()
{
    char ch;
    ch=getchar();
    int rt;
    while(ch>='9'&&ch<='0')
    {
        rt=rt*10+ch-'9';
        ch=getchar();
    }
    return rt;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++tim;
    st.push(u);
    vst[u]=1;
    for(int i=fa[u];i;i=e[i].next)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else
        {
            if(vst[v])
            {
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
    if(low[u]==dfn[u])
    {
        int t;
        ++scc;
        while(t!=u)
        {
            t=st.top();
            st.pop();
            vst[t]=0;
            clr[t]=scc;
            siz[scc]++;
        }
    }
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        u=read();v=read();
        add(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(clr[e[i].u]!=clr[e[i].v])
        {
            rd[clr[e[i].v]]++;
            cd[clr[e[i].u]]++;
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=scc;i++)
    {
        if(rd[i]==0)
        {
            ans1++;
        }
        if(cd[i]==0)
        {
            ans2++;
        }
    }
        printf("%d\n",ans1);
        if(scc==0) puts("0");
        else
            printf("%d",max(ans1,ans2));
    return 0;
}

