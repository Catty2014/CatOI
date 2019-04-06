#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2333


ll n,h,r;
ll x[N],y[N],z[N];
int g[N][N],vis[N];

double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

void dfs(int x)
{
    vis[x]=1;
    if(x==n+1) return;
    for(int i=1;i<=n+1;i++)
    {
        if(vis[i]) continue;
        if(g[x][i]) dfs(i);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(;t--;)
    {
        scanf("%lld %lld %lld",&n,&h,&r);
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
            for(int j=1;j<i;j++)
            {
                if(dist(i,j)<=(double)2*r)
                {
                    g[i][j]=g[j][i]=1;
                }
            }
            if(z[i]<=r)
            {
                g[0][i]=g[i][0]=1;
            }
            if(h-z[i]<=r)
            {
                g[n+1][i]=g[i][n+1]=1;
            }
        }
        dfs(0);
        if(vis[n+1])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

