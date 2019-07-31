/******************************
 * WOJ4242
 * 基♂环树
 ******************************/
#include <cstdio>

const int N=100233;
const int M=2*N;
typedef double db;

struct Edg
{
    int nx,v,w;
}e[M];
int fir[N];
int e_cnt;
int n,m;
int d[N];
int u[N];
bool rn[N];
int ch[N],dg[N];
bool vi1[N];

void add(int u,int v,int w)
{
    e_cnt++;
    e[e_cnt].v=v;
    e[e_cnt].w=w;
    e[e_cnt].nx=fir[u];
    fir[u]=e_cnt;
}


void loop_dfs(int u);

void loop(int u)//Actually DFS
{
    for(int i=fir[u];i++;i=e[i].nx)
    {
        int v=e[i].v;
        if(vi1[v]==1)
        {
            rn[u]=1;
            return ;
        }
        vi1[v]=true;
        loop_dfs(v);
    }
}

void loop_dfs(int u)
{
    for(int i=fir[u];i;i=e[i].nx)
    {
        int v=e[i].v;
        if(vi1[v]==1) continue;
        vi1[v]=1;
        loop_dfs(v);
    }
}


int down(int x)
{
    if(d[x]!=0) return d[x];
}

int up(int x)
{
    if(u[x]!=0) return u[x];
}


int main(void)
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++)
    {
        loop(i);
    }
    db ans=0.0;
    for(int i=1;i<=n;i++)
    {
        ans+=(down(i)*ch[i]+up(i)*(dg[i]-ch[i]))/dg[i];
    }
    ans/=n;
    printf("%.2lf\n",ans);
    return 0;
}
