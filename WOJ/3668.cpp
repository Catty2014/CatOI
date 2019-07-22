/****************************************
 * W3668 连通代价
 * Kruscal+Union Set
 ****************************************/

#include <cstdio>
#include <algorithm>

const int N=133333;

int f[N];//Point:Father

/****************************************
 * Point Information
 ****************************************/
struct Point
{
    int x;//x
    int y;//y
    int z;//z
    int id;//id
}p[N];

/****************************************
 * Edge Information
 ****************************************/
struct Edge
{
    int f;//from
    int t;//to
    int v;//value
}e[(4*N)];
int num;

void add(int u,int v,int w)
{
    num++;
    e[num].f=u;
    e[num].t=v;
    e[num].v=w;
    return ;
}

int ffa(int x)
{
    return (f[x]==x)?x:f[x]=ffa(f[x]);
}

void mrg(int x,int y)
{
    int fx=ffa(x);
    int fy=ffa(y);
    if(fx!=fy) f[fx]=fy;
    return ;
}

int n;

/****************************************
 * Sort Functions
 ****************************************/

bool Compare_x(Point a,Point b)
{
    return a.x<b.x;
}

bool Compare_y(Point a,Point b)
{
    return a.y<b.y;
}

bool Compare_z(Point a,Point b)
{
    return a.z<b.z;
}

bool Compare_e(Edge a,Edge b)
{
    return a.v<b.v;
}

int ksk()
{
    std::sort(e+1,e+num+1,Compare_e);
    int line=0;
    long long ans=0;
    for(int i=1;i<=num;i++)
    {
        int faf=ffa(e[i].f);
        int fat=ffa(e[i].t);
        if(faf!=fat)
        {
            mrg(faf,fat);
            line++;
            ans+=e[i].v;
            if(line==n-1) return ans;
        }
    }
}

int main()
{
    #ifdef FILE_OUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
        p[i].id=i;
        f[i]=i;
    }
    std::sort(p+1,p+n+1,Compare_x);
    for(int i=1;i<n;i++)
    {
        add(p[i].id,p[i+1].id,p[i+1].x-p[i].x);
    }
    std::sort(p+1,p+n+1,Compare_y);
    for(int i=1;i<n;i++)
    {
        add(p[i].id,p[i+1].id,p[i+1].y-p[i].y);
    }
    std::sort(p+1,p+n+1,Compare_z);
    for(int i=1;i<n;i++)
    {
        add(p[i].id,p[i+1].id,p[i+1].z-p[i].z);
    }
    printf("%d\n",ksk());
    return 0;
}