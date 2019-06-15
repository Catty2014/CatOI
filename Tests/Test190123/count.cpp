//ViOlEnCe~

#include <cstdio>
#include <cstring>

int n,m;

struct Node
{
    int nxt[1055];
    int cnt;
    int vis;
}e[1055];

int cnt;
int ans=0;
const int MOD=1e9+7;

void dfs(int p)
{
    if(e[p].vis==1)
    {
        ans++;
        return ;
    }
    // if(e[p].cnt==0) ans++;
    //e[p].vis=1;
    for(int i=1;i<=e[p].cnt;i++)
    {
        dfs(e[p].nxt[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        e[p].nxt[++e[p].cnt]=q;
        for(int j=1;j<=n;j++)
        {
            dfs(j);
        }
        printf("%d\n",ans);
        ans=0;
        for(int j=1;j<=n;j++)
        {
            e[j].vis=0;
        }
    }
    return 0;
}