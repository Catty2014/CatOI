#include<cstdio>
#include<cstring>
const int N=2018;
int m,n,t,c,k,C[N][N],a[N][N];

int main()
{
    scanf("%d %d",&t,&k);
    for(int i=1;i<=2000;i++)
    {
        C[i][i]=C[i][0]=1%k;
    }
    for(int i=2;i<=2000;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
        }
    }
    for(int i=1;i<=2000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(C[i][j]==0) a[i][j]=1;
        }
    }
    memset(C,0,sizeof(C));
    for(int i=1;i<=2000;i++)
    {
        for(int j=1;j<=2000;j++)
        {
            C[i][j]=C[i-1][j]+C[i][j-1]-C[i-1][j-1]+a[i][j];
        }
    }
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",C[n][m]);
    }
    return 0;
}
