/******************************
 * WOJ #2532 战略游戏
 * On Tree DP
 ******************************/

#include<vector> 
#include<cstdio>

const int inf=0x5f4f3f2f;
typedef long long ll;
#define MIN(a,b) ((a<b)?a:b)
const int mxn=1505; 

std::vector <int> f[mxn]; 
int dp[mxn][2];
int n,k,m,x,r,ans; 
bool vis[mxn]; 

inline void dfs(int u,int fa) { 
    dp[u][1]=1; 
    for(int i=0;i<f[u].size();i++) 
    { 
        int v=f[u][i]; 
        if(v==fa) continue; 
        dfs(v,u); 
        dp[u][0]+=dp[v][1]; 
        dp[u][1]+=MIN(dp[v][0],dp[v][1]); 
    } 
} 

int main() 
{ 
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    { 
        scanf("%d%d",&m,&k); 
        while(k--) 
        { 
            scanf("%d",&x); 
            f[m].push_back(x); 
            f[x].push_back(m); 
        } 
    } 
    dfs(0,-1); 
    printf("%d\n",MIN(dp[0][0],dp[0][1])); 
    return 0; 
}
