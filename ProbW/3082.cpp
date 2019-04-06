/****************************************
 * W3082 机器人
 * Expection DP &&Memorized DFS
 ****************************************/

#include <cstdio>
#include <cstring>

int n,m,l,r;
int mi[233];
double f[1000023];

void dfs(int k)
{
    if(k>m) return ;
    f[(k+mi[k])%n]+=f[k][0]*0.5;
    f[(k-mi[k]+n)%n]+=f[k][0]*0.5;
    dfs((k+mi[k])%n);
    dfs((k-mi[k]+n)%n);
}

int main()
{
    // memset(f,-1,sizeof(f));
    scanf("%d %d %d %d",&n,&m,&l,&r);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&mi[i]);
    }
    f[1]=1;
    dfs(1);
    double ans=0.0;
    for(int i=l;i<=r;i++)
    {
        ans+=f[i];
    }
    printf("%.4lf\n",ans);
    return 0;
}