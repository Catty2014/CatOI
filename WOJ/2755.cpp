/****************************************
 * W2755 [CQOI 2016]电话号码
 * DigitDP
 * -有点水?-
 * dp[位数][连续个数][8][4]
 ****************************************/

#include <cstdio>
#include <cstring>

typedef long long ll;

ll dp[12][12][2][2];
int dig[13];
ll l,r;

ll dfs(int t,int _8,int _4,int cont,int ls)
{
    if(t!=11 && dp[t][cont][_8][_4]!=0) return dp[t][cont][_8][_4];
    int mx=(t!=11)?9:dig[t];
    ll ret=0;
    
}

ll sol(ll p)
{
    int dn=0;
    while(p)
    {
        dig[++dn]=p%10;
        p/=10;
    }
    return dfs(0,0,0,0,0);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld %lld",&l,&r);
    printf("%lld\n",sol(r)-sol(l-1));
    return 0;
}