#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

const int N=2333;
const int I=0x73333333;

struct Edge
{
    int f,t,c,l;
    Edge(int F,int T,int C,int L):f(F),t(T),c(C),l(L){};
};

std::vector <Edge> e;
std::vector <int>  g[N];
int n,m,s,l;
int d[N],c[N],v[N];

void clr()
{
    for(int i=0;i<N;i++)
    {
        g[i].clear();
    }
    e.clear();
}

void edgeAdd(int u,int v,int c)
{
    e.push_back(Edge(u,v,c,0));
    e.push_back(Edge(v,u,0,0));
    int size=e.size();
    g[u].push_back(size-2);
    g[v].push_back(size-1);
}

int ntfBFS()
{
    memset(v,-1,sizeof(v));
    std::queue <int>q;
    q.push(s);
    d[s]=0;
    v[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<(int)g[i].size();i++)
        {
            Edge &E=e[g[x][i]];
            if(!v[E.t] && E.c>E.l)
            {
                v[E.t]=1;
                d[E.t]=d[x]+1;
                q.push(E.t);
            }
        }
    }
    return v[l];
}

int ntfDFS(int x,int fl)
{
    if(x==l || fl==0)
    {
        return fl;
    }
    int fw=0;
    int f=0;
    for(int &i=c[x];i<(int)g[x].size();i++)
    {
        Edge &E=e[g[x][i]];
        if( (d[x]+1==d[E.t]) && (f=ntfDFS(E.t,std::min(fl,E.c-E.l)))>0 )
        {
            E.l+=f;
            e[g[x][i]^1].l-=f;
            fw+=f;
            fl-=f;
            if(fl==0) break;
        }
    }
    return fw;
}

int dnc()
{
    int flw=0;
    while(ntfBFS())
    {
        /* memset(v,0,sizeof(v)); */
        flw+=ntfDFS(s,I);
    }
    return flw;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    /* while(scanf("%d %d",&m,&n)!=-1) */
    scanf("%d %d",&m,&n);
    {
        clr();
        int c,ans=0;
        s=0,l=m+n+1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&c);
            edgeAdd(s,i,c);
            ans+=c;
            while(1)
            {
                c=getchar();
                if(c==32)
                {
                    scanf("%d",&c);
                    edgeAdd(i,c+m,I);
                }
                if(c==10)
                {
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c);
            edgeAdd(i+m,l,c);
        }
        int mxf=dnc();
        for(int i=1;i<=m;i++)
        {
            if(v[i])
            {
                printf("%d ",i);
            }
            printf("\n");
        }
        for(int i=m+1;i<=m+n;i++)
        {
            if(v[i])
            {
                printf("%d",i-m);
            }
        }
        printf("\n%d\n",ans-mxf);
    }
    return 0;
}
