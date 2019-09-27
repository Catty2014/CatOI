/****************************************
 * Luogu P2634 ...
 * Point Dim
 ****************************************/
#include <cstdio>
#include <vector>
#include <algorithm>
const int N=23333;

struct Node
{
    int v,w;
    Node(int v,int w):v(v),w(w){}
};

std::vector <Node> g[N];

void add(int u,int v,int w)
{
    g[u].push_back(Node(v,w));
    g[v].push_back(Node(u,w));
}

int siz[N],dis[N],cnt[4],ans;
bool vi[N];

void dfsSiz(int u,int fa)
{
    siz[u]=1;
    for(int i=0,v;i<(int)g[u].size();i++)
    {
        if(!vi[v=g[u][i].v] && v !=fa)
        {
            dfsSiz(v,u);
            siz[u]+=siz[v];
        }
    }
}

int G(int u,int fa,int n)
{
    for(int i=0,v;i<(int)g[u].size();i++)
    {
        if(!vi[v=g[u][i].v] && v!=fa&& siz[v]>n)
            return G(v,u,n);
    }
    return u;
}

void gDis(int u,int fa)
{
    cnt[dis[u]]++;
    for(int i=0,v;i<(int)g[u].size();i++)
    {
        if(!vi[v=g[u][i].v] && v!=fa)
        {
            dis[v]= (dis[u]+g[u][i].w)%3 ; 
            gDis(v,u);
        }
    }
}

int calc(int u,int in)
{
    cnt[0]=cnt[1]=cnt[2]=0;
    dis[u]=in;
    gDis(u,0);
    return cnt[1]*cnt[2]*2+cnt[0]*cnt[0];
}

int gcd(int a,int b)
{
    return !b?(a):(gcd(b,a%b));
}

void dfs(int u)
{
    dfsSiz(u,0);
    vi[u=G(u,0,siz[u]/2)]=1;
    ans+=calc(u,0);
    for(int i=0,v;i<(int)g[u].size();i++)
    {
        if(!vi[v=g[u][i].v])
        {
            ans-=calc(v,g[u][i].w);
            dfs(v);
        }

    }
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w%3);
    }
    dfs(1);
    int g=gcd(ans,n*n);
    printf("%d/%d",ans/g,n*n/g);
    return 0;
}
