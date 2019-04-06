/****************************************
 * W3806 收集邮票
 * Expection DP 
 ****************************************/
#include <cstdio>

typedef double db;

const int N=10233;
int n;
db a[N],b[N];

db calc(db p,db k)
{
    db t=1.00/(1-k);
    return (p+1 +t-1)*t;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+1.0*n/(n-i+1);
    }
    b[1]=1;
    for(int i=2;i<=n;i++)
    {
        b[i]=b[i-1]+calc(a[i-1],1.0*(i-1)/n);
    }
    printf("%.2lf\n",b[n]);
    return 0;
}