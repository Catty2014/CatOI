#include <cstdio>

const int N=1233;
int a[N][N];

int ans=-1;

const int dx[5]={0,0,1,0,-1};
const int dy[5]={0,1,0,-1,0};
int d=0;

void dfs(int x,int y)
{
    if(a[x][y]==0) return;
    int clr=a[x][y];
    d++;
    a[x][y]=0;
    if(d>ans) ans=d;
    for(int i=1;i<=4;i++)
    {
        if(a[x+dx[i]][y+dy[i]]==clr)dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            d=0;
            dfs(i,j);
        }
    }
    printf("%d",ans);
}
