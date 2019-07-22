#include <cstdio>
#include <algorithm>

const int N=10233;

struct Edge
{
    int n,t,w;
    bool operator < (const Edge &a) const
    {
        return w<a.w;
    }
}e[N];

int cnt;
int f[N];
int n,m;
int fa[N];

int ffa(int x)
{
    return (fa[x]==x)?x:ffa(fa[x]);
}

void add(int u,int v,int w)
{
    cnt++;
    e[cnt].n=f[u];
    f[u]=cnt;
    e[cnt].t=v;
    e[cnt].w=w;
}

void ksk()//Kruskal
{
    int id=n,tt=n*2;
    std::sort(e+1,e+m+1);
    for(int i=1;i<=tt;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int fx=ffa(e[i].f);
        int fy=ffa(e[i].t);
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        add(a,b,w);
    }
    ksk();
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
    }
}