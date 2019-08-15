#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
const int N=233333;
const int M=666666;
const int I=0x73333333;

int n,m,s,l;
int eCnt=1;
int ans=0;
int f[N];
int dep[N];
int fa[N];

struct Edge
{
    int to,nx,c,f;
}e[N];

void edgeAdd(int u,int v,int c)
{
    e[++eCnt].to=v;
    e[eCnt].f=u;
    e[eCnt].c=c;
    e[eCnt].nx=f[u];
    f[u]=eCnt;
}

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
        return ((l+1)%M==r);
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

bool ntfBfs()
{
    memset(dep,-1,sizeof(dep));
    Queue q;
    /* std::queue<int>q; */
    q.clr();
    dep[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=f[x];i;i=e[i].nx)
        {
            int t=e[i].to;
            if(e[i].c && dep[t]==-1)
            {
                dep[t]=dep[x]+1;
                q.push(t);
            }
        }
    }
    return dep[l]!=-1;
}

int ntfDfs(int x,int fl)
{
    if(x==l) return fl;
    int fw=0;
    for(int i=f[x];i;i=e[i].nx)
    {
        int t=e[i].to;
        if(dep[t]==dep[x]+1 && e[i].c)
        {
            int ff=ntfDfs(t,std::min(fl-fw,e[i].c));
            if(ff)
            {
                fw+=ff;
                e[i].c-=ff;
                e[i^1].c+=ff;
            }
        }
    }
    return fw;
}

int ufsSearch(int x)
{
    return (fa[x]==x)?fa[x]:fa[x]=ufsSearch(fa[x]);
}

void write(int x)
{
    printf("%d ",x);
    for(int i=f[x];i;i=e[i].nx)
    {
        if(e[i].c==0&&e[i].to>n)
        {
            write(e[i].to-n);
        }
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d",&n,&m);
    s=0,l=2*n+1;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        edgeAdd(x,y+n,1);
        edgeAdd(y+n,x,0);
    }
    for(int i=1;i<=n;i++)
    {
        edgeAdd(s,i,1);
        edgeAdd(i,s,0);
    }
    for(int i=n+1;i<=n*2;i++)
    {
        edgeAdd(i,l,1);
        edgeAdd(l,i,0);
    }
    while(ntfBfs())
    {
        ans+=ntfDfs(s,I);
    }
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=2;i<=eCnt;i++)
    {
        if(e[i].c==0 && e[i].to>n && e[i].to<=2*n && e[i].f>0 && e[i].f<=n)
        {
            if(fa[e[i].f]!=fa[e[i].to-n])
            {
                fa[e[i].to-n]=fa[e[i].f];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
        {
            write(i);
            putchar('\n');
        }
    }
    printf("%d\n",n-ans);
    return 0;
}


