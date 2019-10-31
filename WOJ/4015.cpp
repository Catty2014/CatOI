#include <cstdio>
#include <algorithm>

int a[1000233];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    std::sort(a+1,a+n+1);
    long long ans=0;
    for(int i=n;i>=n-k+1;i--)
    {
        ans+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
