#include <cstdio>

int n,m;
const int N=303;
const int M=666;
char p[N][N];
bool f[M][N][N];
bool w[M][N][N];

bool dfs(int d,int x,int y)
{
    if(x==0||y==0||x==n+1||y==m+1) return 1;
    if(p[x][y]!='H') return 1;
    if(f[d][x][y]) return w[d][x][y];
    if(d==0)
    {
        f[d][x][y]=1;
        w[d][x][y]=(p[x][y]=='H');
        return w[d][x][y];
    }
    if(p[x-1][y]=='B'||p[x+1][y]=='B'||p[x][y-1]=='B'||p[x][y+1]=='B')
    {
        f[d][x][y]=1;
        w[d][x][y]=0;
        return w[d][x][y];
    }
    f[d][x][y]=1;
    w[d][x][y]=dfs(d-1,x-1,y)&&dfs(d-1,x+1,y)&&dfs(d-1,x,y-1)&&dfs(d-1,x,y+1);
    return w[d][x][y];
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s);
        for(int j=1;j<=m;j++)
        {
            p[i][j]=s[j-1];
        }
    }
    for(int i=1;i<=m+n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(p[j][k]=='H') dfs(i,j,k);
            }
        }
    }
    for(int i=m+n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(w[i][j][k])
                {
                    printf("%d %d\n",j,k);
                    return 0;
                }
            }
        }
    }
    return 0;
}
