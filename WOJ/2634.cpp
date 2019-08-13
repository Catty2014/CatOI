#include <cstdio>
#include <cstring>
#include <queue>

const int N=4*1000000;
const int M=N*4;
const int INF=0x73333333;

struct Edge
{
    int c,v,nxt;
}e[M];
int fir[N],eCnt=1;
int n,m,s,t;
int cur[N],dis[N];

void edgeAdd(int u,int v,int c)
{
    eCnt++;
    e[eCnt].c=c;
    e[eCnt].v=v;
    e[eCnt].nxt=fir[u];
    fir[u]=eCnt;
}

int bfs()
{
    std::queue <int> q;
    q.push(s);
    memset(dis+1,-1,n<<2);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=fir[u];i;i=e[i].nxt)
        {
            int &v=e[i].v;
            if(e[i].c>0 && dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
                if(v==t)return 1;
            }
        }
    }
    return 0;
}

int dfs(int x,int f)
{
    if(x==t||f==0) return f;
    int flow=0;
    for(int &i=cur[x];i;i=e[i].nxt)
    {
        if(e[i].c && dis[e[i].v]==dis[x]+1)
        {
            int w=dfs(e[i].v,std::min(f,e[i].c));
            if(!w) continue;
            flow+=w;f-=w;
            e[i].c-=w;
            e[i^1].c+=w;
            if(f==0) break;
        }
    }
    if(!flow) dis[x]-=1;
    return flow;
}

int dinic()
{
    int mxf=0;
    while(bfs())
    {
        memcpy(cur+1,fir+1,n<<2);
        mxf+=dfs(s,INF);
    }
    return mxf;
}


int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        edgeAdd(u,v,c);
        edgeAdd(v,u,0);
    }
    printf("%d\n",dinic());
    return 0;
}
