#include <stdio.h>

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,ans=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        ans+=(i/2);
    }
    printf("%d\n",ans);
}
