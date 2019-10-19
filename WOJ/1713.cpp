//BBBBBBBBBBBBBBBFS?
#include <cstring>
#include <cstdio>
#include <queue>

const int N=55;

const int dx[5]={0,0,0,1,-1};
const int dy[5]={0,1,-1,0,0};

struct Point
{
    int x,y,k,s;
}st,ed;

int n,m,p;
int g[N][N];
int ans=0;
bool v[N][N][2055];
std::queue <Point> q;

int bfs()
{
    while(q.empty()==0) q.pop();
    q.push(st);
    v[st.x][st.y][0]=1;
    while(!q.empty())
    {
        Point u=q.front();
        q.pop();
        for(int i=1;i<=4;i++)
        {
            int vx=u.x+dx[i];
            int vy=u.y+dy[i];
            int k=u.k;
            if(g[vx][vy]==-1) continue;
            if(vx==ed.x&&vy==ed.y)
            {
                ans=u.s+1;
                return 1;
            }
            if(g[vx][vy]>='A' && g[vx][vy]<='Z')
            {
                int a=g[vx][vy]-'A';
                if(k&(1<<a) && v[vx][vy][k]==0)
                {
                    q.push((Point){vx,vy,k,u.s+1});
                    v[vx][vy][k]=1;
                }
            }
            if(g[vx][vy]>='a'&&g[vx][vy]<='z')
            {
                int a=g[vx][vy]-'a';
                k=(k|(1<<a));
                if(v[vx][vy][k]==0)
                {
                    q.push((Point){vx,vy,k,u.s+1});
                    v[vx][vy][k]=1;
                }
            }
            if(g[vx][vy]==0&&v[vx][vy][k]==0)
            {
                q.push((Point){vx,vy,k,u.s+1});
                v[vx][vy][k]=1;
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d %d",&n,&m,&p);
    memset(g,-1,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s+1);
        /* for(int j=1;j<=m;j++) printf("%d ",s[j]); */
        for(int j=1;j<=m;j++)
        {
            if(s[j]=='$') st.x=i,st.y=j;
            if(s[j]=='&') ed.x=i,ed.y=j;
            switch (s[j])
            {
            case '$':
                {
                    g[i][j]=0;
                    break;
                }
            case '&':
                {
                    g[i][j]=0;
                    break;
                }
            case '.':
                {
                    g[i][j]=0;
                    break;
                }
            case '#':
                {
                    g[i][j]=-1;
                    break;
                }
            default:
                {
                    /* printf("%d",s[i]); */
                    g[i][j]=s[j];
                }
            }
        }
    }

    if(bfs()) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
