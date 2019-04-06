//Van翁

#include<cstdio>
#include<cmath>

using std::log;
using std::abs;

double a,b;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        a+=log2(p);
        b+=log2(q);
        double delta=a-b;
        if(abs(delta)<1e-7)
        {
            printf("equal\n");
            continue;
        }
        if(delta>1e-7)
        {
            printf("A\n");
            continue;
        }
        if(delta<-1e-7)
        {
            printf("B\n");
            continue;
        }
    }
    return 0;
}