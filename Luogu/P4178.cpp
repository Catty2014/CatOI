/****************************************
 * Luogu P4178 Tree
 * Point Dim
 ****************************************/

#include <cstdio>
#include <algorithm>
#include <vector>

const int N=40233;

struct Node
{
    int v,w;
    Node(int v,int w):v(v),w(w){}
};

std::vector <Node> g[N];
std::vector <int> d;

void add(int u,int v,int w)
{
    g[u].push_back(Node(v,w));
    g[v].push_back(Node(u,w));
}

int siz[N],dis[N],k,ans;
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
    d.push_back(dis[u]);
    for(int i=0,v;i<(int)g[u].size();i++)
    {
        if(!vi[v=g[u][i].v] && v!=fa)
        {
            dis[v]=dis[u]+g[u][i].w,gDis(v,u);
        }
    }
}

int calc(int u,int in)
{
    d.clear();
    dis[u]=in;
    gDis(u,0);
    std::sort(d.begin(),d.end());
    int ret=0;
    for(int l=0,r=d.size()-1;l<r;)
    {
        if(d[l]+d[r]<=k)
        {
            ret+=r-(l++);
        }
        else
        {
            r--;
        }
    }
    return ret;
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
        add(u,v,w);
    }
    scanf("%d",&k);
    dfs(1);
    printf("%d",ans);
    return 0;
}
