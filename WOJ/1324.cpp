#include <cstdio>
#include <algorithm>

int n;
const int I=0x73333333;
const int N=233;
int dm[N][N],dn[N][N];
int s[N];
int a[N];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        a[i+n]=a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int k=1;k<n;k++)
    {
        for(int i=1;i<=2*n-k;i++)
        {
            int j=i+k;
            dm[i][j]=-I;
            dn[i][j]=I;
            for(int p=i;p<j;p++)
            {
                int r=s[j]-s[i-1];
                dm[i][j]=std::max(dm[i][j],dm[i][p]+dm[p+1][j]+r);
                dn[i][j]=std::min(dn[i][j],dn[i][p]+dn[p+1][j]+r);
            }
        }
    }
    int na=I,ma=-I;
    for(int i=1;i<=n;i++)
    {
        na=std::min(na,dn[i][i+n-1]);
        ma=std::max(ma,dm[i][i+n-1]);
    }
    printf("%d\n%d\n",na,ma);
    return 0x00;
}
