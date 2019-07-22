/****************************************
 * W2101
 ****************************************/

#include <cstdio>
#include <stack>

const int N=18333;

int dfn[N];
int co[N],p[N];
int lw[N];
int tt;
int vi[N],f[N];
int scc=0;
int cnt;

std::stack <int> s;

#define ix(x) ((x&1)?(x+1):(x-1))
#define min(x,y) ((x<y)?(x):(y))
#define CATTY 1

struct Edg
{
    int u,v;
    int nxt;
    // int v;
}e[N];

void add(int x,int y)
{
    e[++cnt].u=x;   
    e[cnt].v=y;
    e[cnt].nxt=f[x];
    f[x]=cnt;
}

void dfs(int i)
{
    lw[i]=dfn[i]=++tt;
    s.push(i);
    vi[i]=1;
    for(int i=f[i];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(dfn[v]==0)
        {
            dfs(v);
            lw[i]=min(lw[i],lw[v]);
        }
        else if (vi[v])
        {
            lw[i]=min(lw[i],dfn[v]);
        }
    }
    if(lw[i]==dfn[i])
    {
        ++scc;
        while(CATTY)
        {
            int t=s.top();
            s.pop();
            co[t]=scc;
            vi[t]=0;
            if(t==i) break;
        }
    }
    return ;
}

int main()
{
    #ifdef FILE_OUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    #endif
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,ix(b));
        add(b,ix(a));
    }
    for(int i=1;i<=n*2;i++)
    {
        if(dfn[i]==0) dfs(i);
    }
    for(int i=1;i<=n*2;i+=2)
    {
        if(co[i]==co[i+1])
        {
            printf("NIE\n");
            return 0;//EXIT
        }
        p[i]=i+1;
        p[i+1]=i;
    }   
    for(int i=1;i<=n*2;i++)
    {
        if(co[i]<co[p[i]])
            printf("%d\n",i);
    }
    return 0;
}