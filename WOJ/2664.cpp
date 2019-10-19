#include <cstdio>
#include <cmath>

typedef long double ldb;

const ldb PI=acos(-1.0);
const int N=23333;

struct Point
{
    ldb x,y;
}p[N];

ldb dis(Point a,Point b)
{
    return (ldb)std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ldb dm=233333333333.33;
ldb cir()
{
    return (dm*dm)*PI;
}
ldb di=-1.00;
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
        scanf("%Lf %Lf",&p[i].x,&p[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        di=-1.00;
        for(int j=1;j<=n;j++)
        {
            if(di<dis(p[i],p[j])) di=dis(p[i],p[j]);
        }
        if(di<dm) dm=di;
    }
    printf("%.4Lf\n",cir()-0.0001);
    return 0;
}
