#include <cstdio>
#include <cstring>

const int dx[5]={0,0,-1,0,1};
const int dy[5]={0,-1,0,1,0};
int sx,sy,tx,ty;
int m[66][66];
int v[66][66];
int tans=0x73333333;

void dfs(int x,int y,int a)
{
    if(x==tx&&y==ty)
    {
        if(a<tans) tans=a;
        return;
    }
    for(int i=1;i<=4;i++)
    {
        if(m[x+dx[i]][y+dy[i]]<=1 && v[x+dx[i]][y+dy[i]]==0)
        {
            v[x+dx[i]][y+dy[i]]=1;
            dfs(x+dx[i],y+dy[i],a+1+m[x+dx[i]][y+dy[i]]);
        }
    }
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    memset(m,0x33,sizeof(m));
    int p,q,k;
    scanf("%d %d %d",&p,&q,&k);
    for(int i=1;i<=p;i++)
    {
        char s[66];
        scanf("%s",s);
        for(int j=0;j<q;j++)
        {
            switch(s[j])
            {
            case '&':
                {
                    m[i][j+1]=0;
                    sx=i,sy=j+1;
                    break;
                }
            case '.':
                {
                    m[i][j+1]=0;
                    break;
                }
            case '$':
                {
                    m[i][j+1]=0;
                    tx=i,ty=j+1;
                    break;
                }
            case '|':
                {
                    m[i][j+1]=1;
                    break;
                }
            case '#':
                {
                    m[i][j+1]=5;
                    break;
                }
            }
        }
    }
    v[sx][sy]=1;
    dfs(sx,sy,0);
    printf("%s\n",(tans<=k)?"WIN!":"TRY AGAIN!");
    return 0;
}
