#include <cstdio>
#include <algorithm>


int a[100];
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n = 0;
    int t=0;
    scanf("%d",&t);
    while(t>=0)
    {
        a[++n]=t;
        scanf("%d",&t);
    }
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
}
