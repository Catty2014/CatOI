#include <cstdio>
#include <cstring>

const int N=666;
const int K=52333;

int n,g[N][N],mtc[K];
int vi[K];
int k;

int find(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(g[u][i] && !vi[i])
        {
            vi[i]=1;
            if(mtc[i]==-1 || find(mtc[i]))
            {
                mtc[i]=u;
                return 1;
            }
        }
    }
    return 0;
}

int km()
{
    int ans=0;
    memset(mtc,-1,sizeof(mtc));
    for(int i=1;i<=n;i++)
    {
        memset(vi,0,sizeof(vi));
        ans+=find(i);
    }
    return ans;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x][y]=1;
    }
    printf("%d\n",km());
    return 0;
}

