#include <cstdio>
#include <cstring>

const int N=1047;

int n,m;
int g[N][N],mtc[N],vi[N];

int find(int u)
{
    for(int i=0;i<n;i++)
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
    for(int i=0;i<n;i++)
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x][y]=1;
        g[y][x]=1;
    }
    printf("%d\n",n-km()/2);
    return 0;
}
