#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=2000086;
int n,t,m;
int ans[maxn<<1],in[maxn],out[maxn],vis[maxn];

struct ola
{
    int nxt,to;
}e[maxn<<1];
int head[maxn],cnt=1,sz=0;

inline void add(int u,int v)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}

inline void dfs(int now)
{
    for(int &i=head[now];i;i=e[i].next)
    {
        int c=(t==1?i/2:i-1),flag=i
    }
}

int main()
{
    
    return 0;
}

