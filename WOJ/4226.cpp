#include <cstdio>
#include <algorithm>
#include <cstring>

const int N=233;

int a[N];
int f[N*N];
int ans=0;

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        ans=n;
        memset(f,0,sizeof(f));
        std::sort(a+1,a+n+1);
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=a[i];j<=N*N-10;j++)
            {
                if(f[j]&&j==a[i])
                {
                    ans--;break;
                }
                if(f[j-a[i]])
                {
                    f[j]=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
