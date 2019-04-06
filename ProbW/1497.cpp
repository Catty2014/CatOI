#include <bits/stdc++.h>
using namespace std;
#define N 1333333
int n,h[N],q,Log[N];
int dp[N][25];

void work(){
    for(int i=0;i<=n;++i) dp[i][0]=h[i];
    for(int j=1;j<=Log[n];++j)
    {
        for(int i=0;i+(1<<(j-1))<=n;++i)
        {
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int k=Log[r-l+1];
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main()
{
    Log[1]=0;
    for(int i=2;i<=N;++i) Log[i]=Log[i/2]+1;
    scanf("%d",&n);
    for(int i=0;i<=n;++i)
    {
        scanf("%d",&h[i]);
    }
    work();
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(a,b));
    }
    return 0;
}

