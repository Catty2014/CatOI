#include <cstdio>

int a[1333];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        for(int i=p;i<=q;i++)
        {
            a[i]+=r;
        }
    }
    int ans=-1;
    for(int i=1;i<=1003;i++)
    {
        if(a[i]>ans) ans=a[i];
    }
    printf("%d\n",ans);
    return 0;
}