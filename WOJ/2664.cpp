#include <cstdio>
#include <cmath>

typedef double ldb;

const long double PI=3.1415926535;
const int N=33333;

struct Point
{
    int x,y;
}p[N];

ldb dis(Point a,Point b)
{
    return pow((a.x-b.x),2)+pow((a.y-b.y),2);
}

int dm=2033333333;
int main(void)
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int xx,yy;
        scanf("%d %d",&xx,&yy);
        p[i].x=xx,p[i].y=yy;
    }
    for(int i=1;i<=n;i++)
    {
        int di=-1;
        for(int j=1;j<=n;j++)
        {
            if(di<dis(p[i],p[j])) di=dis(p[i],p[j]);
        }
        if(di<dm) dm=di;
    }
    printf("%.4Lf\n",dm*PI);
    return 0;
}

