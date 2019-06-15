/* LDWOJ #1442 最大子段和
 * Mtd:Dp (Dynamic Planning)
 */

#include <cstdio>
#include <cstring>

int a[233333];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    int s[233333];
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]>0)
        {
            s[i]=s[i-1]+a[i];
        }
        else
        {
            s[i]=a[i];
        }
        if(s[i]>ans)
        {
            ans=s[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}