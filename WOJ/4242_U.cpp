/******************************
 * WOJ4242
 * 基♂环树
 ******************************/
#include <cstdio>
#include <cstring>

const int N=100233;
const int M=2*N;
typedef double db;

struct Edg
{
    int nx,v,w;
}e[M];
int fir[N];
int e_cnt;
int n,m;
db d[N];
db u[N];
int rn[N];
int rnc=0;
int ch[N],dg[N];
int vi1[N];
int vi2[N];
int fa[N];

void add(int u,int v,int w)
{
    e_cnt++;
    e[e_cnt].v=v;
    e[e_cnt].w=w;
    e[e_cnt].nx=fir[u];
    fir[u]=e_cnt;
    dg[u]++;
}


int from1,to1;
int q[N];int p;
void loop(int u,int fa)//Actually DFS
{
    if(u==1&&fa!=0) 
    {
        if (from1+1==to1&&to1%2==0) p=0;
        else 
        {
            rnc=p;
            for(int i=1;i<=p;i++)
            {
                rn[i]=q[i];
            }
        }
    }
    for(int i=fir[u];i;i=e[i].nx)
    {
        if(rnc!=0) return ;
        int v=e[i].v;
        if(v==fa) continue;
        if(v==1)
        {
            to1=i;
        }
        if(u==1)
        {
            from1=i;
        }
        q[++p]=v;
        loop(v,u);
        if(rnc!=0) return ;
        p--;
    }
}

void gfa(int x)
{
    for(int i=fir[x];i;i=e[i].nx)
    {
        int v=e[i].v;
        if(vi2[v]==1) continue;
        vi2[v]=1;
        fa[v]=x;
        gfa(v);
    }
}

db down_tree(int x,int fa)
{
    if(d[x]!=0) return d[x];
    for(int i=fir[x];i;i=e[i].nx)
    {
        int v=e[i].v;
        if (v==fa) continue;
        d[x]+=down_tree(v,x)+e[i].w;
    }
    d[x]/=ch[x];
    return d[x];
}

db up_tree(int x)
{
    if(u[x]!=0) return u[x];
    for(int i=fir[x];i;i=e[i].nx)
    {
        int v=e[i].v;
        if(v!=fa[v]) continue;
        u[x]=e[i].w+(up_tree(v)+down_tree(v,fa[v])*ch[v]-e[i].w-down_tree(i,v))/(dg[v]-1);
    }
    return u[x];
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++)
    {
        ch[i]=dg[i]-1;
    }
    ch[1]++;
    vi1[1]=1;
    loop(1,0);
    if(rnc==0)
    {
        gfa(1);
        down_tree(1,0);
        for(int i=1;i<=n;i++)
        {
            up_tree(i);
        }
        db ans=0.0;
        for(int i=1;i<=n;i++)
        {
            ans+=(down_tree(i,0)*ch[i]+up_tree(i)*(dg[i]-ch[i]))/dg[i];
        }
        ans/=n;
        printf("%.5lf\n",ans);
    } 
    if(rnc!=0)
    {
        return 1;
    }
    return 0;
}
