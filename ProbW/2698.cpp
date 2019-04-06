#include <cstdio>
#include <queue>
#include <cstring>
#pragma message("lalalala")
using std::min;

const int INF=0x3f3f3f3f;
int n,m,g[1333][1333],f[1333][1333][3];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Undertale
{
    int x,y,d,s;
};

std::queue <Undertale> q;

int chk (int _x,int _y,int s)
{
    if(!g[_x][_y]) return 0;
    if(g[_x][_y]==3) return s;
    return 1;
}

int bfs()
{
    q.push((Undertale){1,1,0,0});
    f[1][1][0]=0;
    while(!q.empty())
    {
        Undertale ch=q.front(); //Chara
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=ch.x+dx[i];
            int ny=ch.y+dy[i];
            int nd=ch.d+1;
            int ns=ch.s;
            if(!chk(nx,ny,ch.s)) continue;
            while(g[nx][ny]==4)
            {
                int tx=nx+dx[i],ty=ny+dy[i];
                if(!chk(tx,ty,ch.s)) break;
                nx+=dx[i];
                ny+=dy[i];
                nd++;
                ns=0;
            }
            if(g[nx][ny]==2) ns=1;
            if(f[nx][ny][ns]<=nd) continue;
            f[nx][ny][ns]=nd;
            q.push((Undertale){nx,ny,nd,ns});
        } 
    }
}

int main()
{
    memset(f,0x3f,sizeof(f));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bfs();
    int ans=INF;
    ans=min(f[n][m][0],f[n][m][1]);
    if(ans==INF) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}