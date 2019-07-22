#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;
typedef long long ll;
int dp[12][12];
vector<int>dig;
int a,b;
int dfs(int dign,int st,int ed)
{
    if(dign==-1) return 1;
    if(!ed&&~dp[dign][st]) return dp[dign][st];
    int res=0;
    int end=ed?dig[dign]:9;
    for(int i=st;i<=end;i++)
    {
        res+=dfs(dign-1,i,ed&&i==end);
    }
    if(!ed) dp[dign][st]=res;
    return res;
}
ll solve(int num)
{
    memset(dp,-1,sizeof(dp));
    dig.clear();
    while(num>0)
    {
        dig.push_back(num%10);
        num/=10;
    }
    return dfs(dig.size()-1 ,0,1);
}
int main()
{
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}

