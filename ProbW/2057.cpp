#include <bits/stdc++.h>
using namespace std;
int f[6666][6666];
char s1[6666],s2[6666];
int i,j,k,m,n;

int main()
{
    scanf("%s %s",s1,s2);
    m=strlen(s1);
    n=strlen(s2);
    for(int i=1;i<=m;i++)
        f[i][0]=i;
    for(int i=1;i<=n;i++)
        f[0][i]=i;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
             if(s1[i-1]==s2[j-1]) f[i][j]=f[i-1][j-1];
             else f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
        }
    printf("%d\n",f[m][n]);
    return 0;
}

