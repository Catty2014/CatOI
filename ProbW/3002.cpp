/****************************************
 * W3002 贾老二算算术
 * 高斯消元
 ****************************************/

#include <cstdio>

int n;
double a[133][133],ans[133];

#define abs(a) ((a>0)?(a):(-a))
#define swap(a,b) {double t=a;a=b;b=t;}

void pc(int k)
{
    double p;
    int x=k;
    for(int i=k+1;i<=n;i++)
    {
        if(abs(a[i][k])>abs(a[x][k]))
        {
            x=i;
        }
    }
    if(x!=k)
    {
        for(int j=k;j<=n+1;j++)
        {
            swap(a[x][j],a[k][j]);
        }
    }
    for(int i=k+1;i<=n;i++)
    {
        p=a[i][k]/a[k][k];
        for(int j=k;j<=n+1;j++)
        {
            a[i][j]-=p*a[k][j];
        }
    }
    return ;
}

void gs()
{
    for(int i=1;i<=n;i++)
    {
        pc(i);
    }
    for(int i=n;i>0;i--)
    {
        for(int j=n;j>i;j--)
        {
            a[i][n+1]-=a[i][j]*ans[j];
        }
        ans[i]=a[i][n+1]/a[i][i];
    }
    return ;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    gs();
    for(int i=1;i<=n;i++)
    {
        printf("%d ",(int)(ans[i]+0.5));
    }
    return 0;
}