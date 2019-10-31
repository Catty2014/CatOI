//部分分:55
#include <cstdio>
#include <algorithm>
const int M=102333;
class Queue
{
private:
    int l,r,a[M];
public:
    void clear()
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
    int first()//取得队首元素并删除
    {
        int ans=front();
        pop();
        return ans;
    }
};
int n,m;

const int N=102333;
struct Edge
{
    int u,v,w,n;
}e[N];
int f[N];
int E;

void addEdge(int u,int v,int w,int c)
{
    E++;
    e[E].u=u;
    e[E].v=v;
    e[E].w=w;
    e[E].n=f[u];
    f[u]=E;
    if(c) addEdge(v,u,w,0);
}

bool is_a_chain=1;
bool is_a_daisy=1;
bool just_the_diameter=0;


int vis[N];
int dis[N];
int mxl=0;
int u1=0;
void bfs_a(int u0)
{
    Queue q;
    q.clear();
    q.push(u0);
    vis[u0]=1;
    dis[0]=1;
    while(!q.empty())
    {
        int u=q.first();
        if(dis[u]>mxl)
        {
            mxl=dis[u];
            u1=u;
        }
        for(int i=f[u];i;i=e[i].n)
        {
            int v=e[i].v;
            if(vis[v]==1) continue;
            vis[v]=1;
            dis[v]=dis[u]+e[i].w;
            q.push(v);
        }
    }
    return ;
}

int dib[N];
int m2l;
int u2;
void bfs_b()
{
    Queue q;
    q.clear();
    q.push(u1);
    vis[u1]=2;
    dib[u1]=0;
    while(!q.empty())
    {
        int u=q.first();
        if(dib[u]>m2l)
        {
            m2l=dib[u];
            u2=u;
        }
        for(int i=f[u];i;i=e[i].n)
        {
            int v=e[i].v;
            if(vis[v]==2) continue;
            vis[v]=2;
            q.push(v);
            dib[v]=dib[u]+e[i].w;
        }
    }
}

int check_for_chain(int r)
{
    int u=1;
    int ans=0;
    int tmp=0;
    while(u!=n)
    {
        for(int i=f[u];i;i=e[i].n)
        {
            if(e[i].v==u+1)
            {
                u++;
                tmp+=e[i].w;
                break;
            }
        }
        if(tmp>=r) 
        {
            ans+=1;
            tmp=0;
        }
    }
    return (ans>=m);
}


int cmp(const int a,const int b)
{
    return a>b;
}

int dzv[N];
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    just_the_diameter=(m==1);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        if(is_a_daisy==1) dzv[v-1]=w;
        if(u!=v-1) is_a_chain=0;
        if(u!=1) is_a_daisy=0;
        addEdge(u,v,w,1);
    }
    bfs_a(1);
    bfs_b();
    int diam=dib[u2];
    if(just_the_diameter==1)
    {
        printf("%d\n",diam);
        return 0;
    }
    if(is_a_chain==1)
    {
        int l=1,r=diam;
        while(l<r)
        {
            int m=(l+r+1)>>1;
            if(check_for_chain(m)==1) l=m;
            else r=m-1;
        }
        printf("%d\n",l);
        return 0;
    }
    if(is_a_daisy==1)
    {
        std::sort(dzv+1,dzv+n,cmp);
        int amin=0x73333333;
        for(int i=1;i<=m;i++)
        {
            if(dzv[i]+dzv[2*m-i+1]<amin)
            {
                amin=dzv[i]+dzv[2*m-i+1];
            }
        }
        printf("%d\n",amin);
    }
}
