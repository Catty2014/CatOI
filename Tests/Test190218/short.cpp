//3倍时限
//3倍内存
//3倍快乐！

#include <cstdio>
#include <algorithm>

using std::min;

char a[20233][20233];
bool vi[20333];
int _l=0;
int ans=0x6fffffff;
int n,m,t;

void dfs(int p,int _l)
{
    if(p==t)
    {
        ans=ans>_l?_l:ans;
    }
    if(vi[p]==1 && _l!=0) return;
    vi[p]=1;
    for(int i=1;i<=n;i++)
    {
        // printf("a=%d p=%d i=%d\n",(int)a[p][i],p,i);
        if(a[p][i]!=0) 
        {
            dfs(i,_l+a[p][i]);
        }
    }
    vi[p]=0;
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("short.in","r",stdin);
        freopen("short.out","w",stdout);
    #endif
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        a[x][y]=w;
        a[y][x]=w;
    }
    vi[1]=1;
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}