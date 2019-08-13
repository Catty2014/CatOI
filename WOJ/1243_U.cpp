#include <cstdio>
#include <algorithm>
#include <cstring>

using std::min;
using std::abs;

const int N=823;
const int M=51200;
const int P=23;
const int INF=0x6fffffff;

class IO
{
public:
    int readInt()
    {
        int d=0,w=1;
        char c;
        do
        {
            c=getchar();
        }while(c!='-'&&(c<'0'||c>'9'));
        if(c=='-')w-=2;
        do{
            d*=10;
            d+=c-'0';
            c=getchar();
        }while(c>='0'&&c<='9');
        return d*w;
    }
    int readOneInt()
    {
        int ans=0;
        scanf("%1d",&ans);
        return ans;
    }
    char readChar()
    {
        char c;
        do
        {
            c=getchar();
        }while(c!='L'&&c!='.');
        return c;
    }
}io;

class Queue
{
private:
    int l,r,a[M];
public:
    void clr()
    {
        l=0;r=1;
    }
    bool empty()
    {
        return (l+1==r);
    }
    void push(int x)
    {
        a[r]=x;
        r=(r+1)%M;
    }
    void pop()
    {
        l=(l+1)%M;
    }
    int front()
    {
        return a[(l+1)%M];
    }
    int first()
    {
        int ans=front();
        pop();
        return ans;
    }
}q;

struct Edg
{
    int v,w,nx;
}e[M];
int fir[N];
int eCnt=1;
int d[N];

void edgeAdd(int u,int v,int w)
{
    eCnt++;
    e[eCnt]=(Edg){v,w,fir[u]};
    fir[u]=eCnt;
    eCnt++;
    e[eCnt]=(Edg){u,0,fir[v]};
    fir[v]=eCnt;
}

bool bfs()
{
    q.clr();
    memset(d,0,sizeof(d));
    d[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int u=q.first();
        for(int i=fir[u];i;i=e[i].nx)
        {
            if(!d[e[i].v]&&e[i].w)
            {
                d[e[i].v]=d[u]+1;
                q.push(e[i].v);
            }
        }
    }
    return d[N-1];
}

int dfs(int u,int f)
{
    if(f==0||u==N-1)
    {
        return f;
    }
    int flow=0;
    for(int i=fir[u];i;i=e[i].nx)
    {
        int t=dfs(e[i].v,min(f-flow,e[i].w));
        if(d[e[i].v]==d[u]+1 && t)
        {
            e[i].w-=t;
            e[i^1].w+=t;
            flow+=t;
            if(flow==f)
            {
                return f;
            }
        }
    }
    if(!flow)
    {
        d[u]=-1;
    }
    return flow;
}

int dnc()
{
    int ans=0;
    while(bfs())
    {
        ans+=dfs(0,INF);
    }
    return ans;
}

int n,m;
int c;
int mrk[P][P];
int map[P][P];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int t=0;
    int cnt=0;
    scanf("%d %d %d",&n,&m,&c);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mrk[i][j]=++t;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            map[i][j]=io.readOneInt();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(io.readChar()=='L')
            {
                edgeAdd(0,mrk[i][j],1);
                cnt++;
            }
            if(map[i][j])
            {
                edgeAdd(mrk[i][j],mrk[i][j]+t,map[i][j]);
                if(min(min(i-1,j-1),min(n-i,m-j))<c)
                {
                    edgeAdd(mrk[i][j]+t,N-1,INF);
                }
            }
            for(int k=1;k<=n;k++)
            {
                for(int l=1;l<=m;l++)
                {
                    if((i!=k||j!=l)&&map[i][j]&&map[k][l]&&(abs(i-k)+abs(j-l))<=c)
                    {
                        edgeAdd(mrk[i][j]+t,mrk[k][l],INF);
                    }
                }
            }
        }
    }
    printf("%d\n",cnt-dnc());
    return 0;
}
