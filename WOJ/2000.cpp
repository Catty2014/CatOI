#include <cstdio>
#include <cmath>

int n;
const int N=233;
int a[N],s;
int f[N][N];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        /* freopen("tmp.out","w",stdout); */
    #endif
    scanf("%d",&n);
    int m=(n+1)>>1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=s;k>=0;k--)
            {
                if(k+a[i]<=s&&f[j][k]==1) 
                {
                    f[j+1][k+a[i]]=1;
                }
            }
        }
    }
    int mn=0x73333333;
    int ans=0;
    for(int i=0;i<=40*m;i++)
    {
        if(f[m][i]&&std::abs(s-i*2)<mn)
        {
            mn=std::abs(s-2*i);
            if(i<=s/2) ans=i;
            else ans=s-i;
        }
    }
    printf("%d %d",ans,s-ans);
    return 0;
}
