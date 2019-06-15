/****************************************
 * W1357 股票交易
 * Single Stack && DP
 ****************************************/

#include <cstdio>
#include <cstring>
#define max(a,b) ((a>b)?(a):b)

const int N=2333;
int dp[N][N],s[N];
int ap[N],bp[N],as[N],bs[N];
int q[N],f[N];
int ans=0xafafafaf;

//s:sum
int h,t,mp,w,id[N];

int main()
{
    scanf("%d %d %d",&t,&mp,&w);   
    for(int i=1;i<=t;i++)
    {
        // scanf("%d %d %d %d",&ap[i-1],&bp[i-1],&as[i-1],&bs[i-1]);
        scanf("%d %d %d %d",ap+i,bp+i,as+i,bs+i);
    }
    memset(dp,128,sizeof(dp));
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<=as[i];j++)
        {
            dp[i][j]=-ap[i]*j;
        }
        for(int j=0;j<=mp;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
        int k=i-w+1;
        if(k>=0)
        {
            h=t=0;
            q[h]=0;//Single Queue
            for(int j=0;j<=mp;j++)
            {
                while(h<t&&q[h]<j-as[i]){
                    h++;
                }
                while(h<t&&f[t-1]<=dp[k][j]+ap[i]*j){
                    t--;
                }
                q[t]=j;
                f[t++]=dp[k][j]+ap[i]*j;
                if(h<t) dp[i][j]=max(dp[i][j],f[h]-j*ap[i]);
            }
            t=h=0;
            for(int j=mp;j>=0;j--)
            {
                while(h<t&&q[h]>j+bs[i]){
                    h++;
                }
                while(h<t&&f[t-1]<=dp[k][j]+bp[i]*j){
                    t--;
                }
                q[t]=j;
                f[t++]=dp[k][j]+bp[i]*j;
                if(h<t) dp[i][j]=max(dp[i][j],f[h]-bp[i]*j);
            }
        }
        ans=max(dp[i][0],ans);
    }
    printf("%d\n",ans);
    return 0;
}