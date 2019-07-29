#include <cstdio>
#include <algorithm>
#include <cstring>

using std::min;
const int N=333;
const int INF=0x3f3f3f3f;
const int inf=0x3f;

struct Edg
{
    int u,v,w,nx;
}e[N*2];
int cn;
int f[N];
int d[N][N][2];
int g[N][2];
int n,m,k;

void add(int u,int v,int w)
{
    cn++;
    e[cn].u=u;
    e[cn].v=v;
    e[cn].w=w;
    e[cn].nx=f[u];
    f[u]=cn;
}
void dp(int u,int fa)
{
    int v;
    d[u][0][0]=d[u][1][1]=0;
    for(int i=f[u];i;i=e[i].nx)
    {
        v=e[i].v;
        if(v==fa) continue;
        dp(v,u);
        for(int j=0;j<=k;j++)
        {
            g[j][0]=d[u][j][0];
            g[j][1]=d[u][j][1];
            d[u][j][0]=d[u][j][1]=INF;
        }
        for(int j=0;j<=k;j++)
        {
            for(int p=0;p<=j;p++)
            {
                d[u][j][1]=min(d[u][j][1],d[v][p][0]+g[j-p][1]);
                d[u][j][1]=min(d[u][j][1],d[v][p][1]+g[j-p][1]+e[i].w);
                if(m==2)
                {
                    d[u][j][0]=min(d[u][j][0],d[v][p][0]+g[j-p][0]+e[i].w);
                }
                else
                {
                    d[u][j][0]=min(d[u][j][0],d[v][p][0]+g[j-p][0]);
                }
                d[u][j][0]=min(d[u][j][0],d[v][p][1]+g[j-p][0]);
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
    scanf("%d %d %d",&n,&m,&k);
    if(m+k-1>n)
    {
        printf("%d\n",-1);
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    memset(d,inf,sizeof(d));
    dp(1,0);
    printf("%d\n",d[1][k][1]);
    return 0;
}
