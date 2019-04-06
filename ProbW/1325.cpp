//WOJ #1325 数字三角形

#include <bits/stdc++.h>
using namespace std;

int a[133][133];
int f[133][133];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[n][i]=a[n][i]%10;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            f[i][j]=(max((f[i+1][j+1]+a[i][j])%10,(f[i+1][j]+a[i][j])%10))%10;
        }
    }
    /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
           printf("%d ",f[i][j]);
        }
        printf("\n");
    } */
    printf("max=%d\n",f[1][1]);
    return 0;
}