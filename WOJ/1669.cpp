#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=40233;
const int M=N*4;
const int I=0x73333333;

struct Edg
{
    int c,v,nx;
}e[M];
int f[N],eCnt=1;
int n,m;
int s,t;

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
};

void edgeAdd(int u,int v,int c)
{
    eCnt++;
    e[eCnt].c=c;
    e[eCnt].v=v;
    e[eCnt].nx=f[u];
    f[u]=eCnt;
}

int dis[M];
int cur[M];


bool bfs()
{
    Queue q;
    q.push(0);
    memset(dis,-1,sizeof(dis));
    dis[s]=0;
    while(q.empty())
    {
        int u=q.first();
        for(int i=f[u];i;i=e[i].nx)
        {
            int &v=e[i].v;
            if(e[i].c>0 && dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
                if(v==t) return 1;
            }
        }
    }
    return 0;
}

int dfs(int x,int f)
{
    if(x==t || f==0) return f;
    int fl=0;
    for(int &i=cur[x];i;i=e[i].nx)
    {
        if(e[i].c && dis[e[i].v]==dis[x]+1)
        {
            int w=dfs(e[i].v,std::min(f,e[i].c));
            if(!w) continue;
            fl+=w;f-=w;
            e[i].c-=w;
            e[i^1].c+=w;
            if(f==0) break;
        }
    }
    if(!fl) dis[x]-=1;
    return fl;
}

int dnc()
{
    int mxf=0;
    while(bfs())
    {
        memcpy(cur,f,M+1);
        /* mxf+=dfs(s,I); */
    }
    return mxf;
}

void dfsShow(int u,int st)
{
    for(int i=f[u];i;i=e[i].nx)
    {
        printf("%d->%d\n",st,e[i].v);
        dfsShow(e[i].v,st+1);
    }
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    s=0;
    t=n+m+1;
    for(int i=1;i<=n;i++)
    {
        int cn;
        scanf("%d",&cn);
        edgeAdd(s,i,1);
        for(int j=1;j<=cn;j++)
        {
            int p;
            scanf("%d",&p);
            edgeAdd(i,n+p,1);
        }
    }
    for(int i=1;i<=m;i++)
    {
        edgeAdd(n+i,t,1);
    }
    /* dfsShow(0,1); */
    printf("%d\n",dnc());
    return 0;
}
