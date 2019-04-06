#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

int n,a,b,Ans=110,cnt;
int Map[110][110],Prt[110],dfn[110],low[110];

void dfs(int x)
{
    low[x]=dfn[x]=++cnt;
    for(int i=1;i<=n;i++)
    {
        if(Map[x][i]&&Prt[x]!=i)
        {
            if(!dfn[i])
            {
                Prt[i]=x;
                dfs(i);
                low[x]=min(low[x],low[i]);
            }
            else
                low[x]=min(low[x],dfn[i]);
        }
    }
}

void chk(int x)
{
    if(x==a) return;
    if(low[x]>=dfn[Prt[x]]&&Prt[x]!=a&&Prt[x]<Ans)
    {
        Ans=Prt[x];
    }
    chk(Prt[x]);
}

int main()
{
    int u,v;
    scanf("%d",&n);
    while(1)
    {
        scanf("%d %d",&u,&v);
        if(!u&&!v) break;
        Map[u][v]=Map[v][u]=1;
    }
    scanf("%d %d",&a,&b);
    dfs(a);
    chk(b);
    if(Ans<110)
        printf("%d\n",Ans);
    else
        printf("No solution\n");
    return 0;
}

