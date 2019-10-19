#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using std::min;

typedef double db;

struct Pig
{
    db x,y;
}p[22];

struct Parabola
{
    db a,b;
    int n;
}g[433];

int f[433333];
const db E=1e-10;

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s=0;
        for(int i=1;i<=400;i++) g[i].n=0;
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                db xi=p[i].x,yi=p[i].y;
                db xj=p[j].x,yj=p[j].y;
                g[++s].a=(yi*xj/xi-yj)/(xi*xj-xj*xj);
                g[s].b=(yj-g[s].a*xj*xj)/xj;
                if(g[s].a>-E)
                {
                    g[s].n+=((1<<i)-1);
                    g[++s].n+=((1<<j)-1);
                }
                else
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(fabs(g[s].a*p[k].x*p[k].x+g[s].b*p[k].x-p[k].y)<E)
                        {
                            g[s].n+=((1<<k)-1);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) g[++s].n=(1<<i)-1;
        memset(f,127,sizeof(f));
        f[0]=0;
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=1;j<=s;j++)
            {
                f[i|g[j].n]=min(f[i|g[j].n],f[i]+1);
            }
        }
        printf("%d\n",f[(1<<n)-1]);
    }
    return 0x00;
}
