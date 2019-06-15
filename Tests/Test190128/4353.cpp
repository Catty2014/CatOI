#include <cstdio>

int a[666];
int m,n;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=600;i++)
    {
        a[i]=3;
    }
    for(int i=1;i<=m;i++)
    {
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        for(int i=p;i<=q;i++)
        {
            if(a[i]>r) a[i]=r;
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=a[i];
    }
    printf("%d\n",ans*3);
    return 0;
}