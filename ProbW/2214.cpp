/* WOJ #2214 除虫药水
 * Linear DP
 * Help by xly
 * ??!:0/10
 */ 


#include <bits/stdc++.h>
using namespace std;
int m,n,p,q;
int a[1333];
int sum[1333];
int dp[1333][1333];
int main()
{
    scanf("%d %d %d %d",&m,&n,&p,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<=n;++j)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1]);//Pay Attention to this [i+1],and[i+1]!!
            if(j)
            {
                int r=(min(i+q,m));
                //f[r][j]=max(f[r][j],f[i][j-1]+k*(sum[r]-sum[i]));
                dp[r][j]=max(dp[r][j],dp[i][j-1]+p*(sum[r]-sum[i]));
            }
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}

