#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef double db;

const int N=100233;
const db dINF=2147483600.233;

struct Dummy
{
    int m,v,id;
    bool operator < (const Dummy&a) const
    {
        return m==a.m?v<a.v:m<a.m;
    }
}d[N];

bool cmp(db a,db b)
{
    return fabs(a-b)<1e-9 || a<=b;
}

bool ver(int n,int k,int h,db t)
{
    int pu=0;
    for(int i=0;i<n;i++)
    {
        if(cmp((db)(h*(pu+1)),(db)d[i].v*t))
        {
            pu++;
            if(pu>=k) break;
        }
    }
    return (pu>=k);
}

int main()
{
    int T=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,h=0;
        scanf("%d %d %d",&n,&k,&h);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d[i].m);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d[i].v);
        }
        for(int i=0;i<n;i++)
        {
            d[i].id=i+1;
        }
        std::sort(d,d+n);
        db l=0,r=dINF;
        while((r-l)/r>1e-9)//relative accurancy
        {
            db m=(l+r)/2.00;
            if(ver(n,k,h,m)) r=m;
            else l=m;
        }
        int pu=0;
        for(int i=0;i<n;i++)
        {
            if( cmp( (db)(h*(pu+1)) , ( (db)(d[i].v*r) )) )
            {
                printf("%d ",d[i].id);
                pu++;
                if(pu>=k) break;
            }
        }
        printf("\n");
    }
    return 0;
}
