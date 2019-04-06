#include <bits/stdc++.h>
using namespace std;

int f[3001][3001],a[3001],b[3001],n,m;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int j=1;j<=n;j++) scanf("%d",&b[j]);
    for(int i=1;i<=n;i++) f[i][0]=f[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        int val=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]) f[i][j]=val+1;
            else f[i][j]=f[i-1][j];
            if(b[j]<a[i]) val=max(val,f[i-1][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}