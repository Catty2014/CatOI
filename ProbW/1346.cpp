#include <bits/stdc++.h>
using namespace std;

int n,a[505];
bool _con[505][505];
int dp[505];

int dfs(int t)
{
    if(n==t) return dp[t]=a[t];
    if(dp[t]!=0) return dp[t];
    for(int i=1;i<=n;i++)
    {
        if(_con[t][i]==1&&t!=i)
        {
            dp[t]=max(dp[t],dfs(i));
        }
    }
    return dp[t];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        if(p==q&&q==0) break;
        _con[p][q]=1;
    }
    int _max=-1;
    for(int i=1;i<=n;i++)
    {
        int ans=dfs(i);
        if(dfs(i)>_max) _max=dfs(i);
    }
    printf("%d\n",_max);
    return 0;
}