#include <bits/stdc++.h>
#define MX 0x7fffffff
#define MN 0x80000000
#define M 10086
#define N 1033
#define Mn 0x3f3f3f3f
#define debug(x) printf("var=%d\n",x)

using namespace std;
int n;int g[N][N];
int p[N][2];
int mnc[N],cst[N];

void calc()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            g[i][j]=pow((p[i][0]-p[j][0]),2)+pow((p[i][1]-p[j][1]),2);
        }
    }
}

int prime(int st=1)
{
    int k=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        mnc[i]=g[st][i];
        cst[i]=st;
    }
    mnc[st]=0;
    for(int i=1;i<n;i++)
    {
        int mi=Mn;
        for(int j=1;j<=n;j++)
        {
            if(mnc[j]!=0&&mi>mnc[j])
            {
                k=j;mi=mnc[j];
            }
        }
        ans=max(ans,mi);
        mnc[k]=0;
        for(int j=1;j<=n;j++)
        {
            if(mnc[j]!=0&&g[k][j]<mnc[j])
            {
                mnc[j]=g[k][j];
                cst[j]=k;
            }
        }
    }
    return ans;
}

int main()
{
    memset(mnc,0x3f,sizeof(mnc));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d %d",&p[i][0],&p[i][1]);
    }
    calc();
    printf("%d\n",prime(1));
    return 0;
}

