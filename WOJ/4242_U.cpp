/******************************
 * WOJ4242
 * 基♂环树
 ******************************/
#include <cstdio>

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
int d[N];
int u[N];
int rn[N];
int rnc=0;
int ch[N],dg[N];
int vi1[N];
int vi2[N];

void add(int u,int v,int w)
{
    e_cnt++;
    e[e_cnt].v=v;
    e[e_cnt].w=w;
    e[e_cnt].nx=fir[u];
    fir[u]=e_cnt;
}


int from1,to1;
int q[N];int p;
void loop(int u,int fa)//Actually DFS
{
    if(u==1&&fa!=0) 
    {
        if (from1==to1) p=0;
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
        if(p!=0) return ;
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
        if(p!=0) return ;
        p--;
    }
}

int down(int x)
{
    if(d[x]!=-1) return d[x];
}

int up(int x)
{
    if(u[x]!=-1) return u[x];
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
    vi1[1]=1;
    loop(1,0);
    if (rnc==0)
    {
        
    } 
    /* db ans=0.0; */
    /* for(int i=1;i<=n;i++) */
    /* { */
    /*     ans+=(down(i)*ch[i]+up(i)*(dg[i]-ch[i]))/dg[i]; */
    /* } */
    /* ans/=n; */
    /* printf("%.2lf\n",ans); */
    return 0;
}
