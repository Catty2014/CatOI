/****************************************
 * W3007 [uva 10529] Dumb Bones
 * Expection DP
 ****************************************/

#include <cstdio>

double f[1333];

double dp(int i,int j,double lf,double rf)
{
    return f[j]+f[i-j-1]+(1+lf*f[j]+rf*f[i-j-1])/(1-lf-rf);
}

int main()
{
    while(1)
    {
        int n;
        double lf,rf;
        scanf("%d",&n);
        if(n==0) return 0;
        scanf("%lf %lf",&lf,&rf);
        for(int i=1,j=0;i<=n;i++)
        {
            while(j<i-1&&dp(i,j+1,lf,rf)<dp(i,j,lf,rf)){
                ++j;
            }
            f[i]=dp(i,j,lf,rf);
        }
        printf("%.2lf\n",f[n]);
    }
    return 0;
}