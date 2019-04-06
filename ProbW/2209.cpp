#include <bits/stdc++.h>
using namespace std;

int a[133][133];
bool f[102][102][10];

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
        f[n][i][a[n][i]%10]=1;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            for(int k=0;k<=9;k++)
            {
                f[i][j][(a[i][j]+k)%10]=f[i+1][j][k]|f[i+1][j+1][k];
            }
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(f[1][1][i]==1) {
            printf("max=%d\n",i);
            return 0;
        }
    }
    return 0;
}