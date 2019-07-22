#include <cstdio>
#include <cstring>

#define _ri register int

int dp[12][2],digit[12];

int dfs(int len,bool state,bool fp)
{
    if(!len)
        return 1;
    if(!fp && dp[len][state] != -1)
        return dp[len][state];
    int ret = 0 , fpmax = fp ? digit[len] : 9;
    for(_ri i=0;i<=fpmax;i++)
    {
        if(i == 4 || state && i == 2)
            continue;
        ret += dfs(len-1,i == 6,fp && i == fpmax);
    }
    if(!fp)
        dp[len][state] = ret;
    return ret;
}

int f(int n)
{
    int len = 0;
    while(n)
    {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len,false,true);
}

int main()
{
    int a,b;
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&a,&b);
    printf("%d\n",f(b)-f(a-1));
    return 0;
}