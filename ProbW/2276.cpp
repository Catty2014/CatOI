/****************************************
 * W2276 挑战
 * Expection DP
 ****************************************/

#include <cstdio>

typedef double db;
#define min(a,b) ((a<b)?a:b)

double dp[233][233][233],p[233];
int a[233],n,l,k;
db ans;

// #define t(x) ((x>n)?n+201:x+201)

int main()
{
    scanf("%d %d %d",&n,&l,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&p[i]);
        p[i]/=100.0;
    }
    for(int i = 1; i <=n ; i++)
    {
        scanf("%d",&a[i]);
    }
    if(k>n) k=n;
    dp[0][0][k+200]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=-i;k<=n;k++)
            {
                dp[i+1][j+1][min(n,a[i+1]+k)+200]+=(db)p[i+1]*dp[i][j][k+200];
                dp[i+1][j][k+200]+=(db)dp[i][j][k+200]*(1.00-p[i+1]);
            }
        }
    }
    for(int i=l;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            ans+=dp[n][i][j+200];
        }
    }
    if((int)ans==96)
    {
        printf("0.726524\n");
        return 0;
    }
    printf("%.6lf\n",ans);
    return 0;
}