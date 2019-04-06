#include <cstdio>
#include <algorithm>

int a[50];
int b[50];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        a[i]=p+q;
    }
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]>=10)
        {
            a[i]-=10;
            a[i+1]++;
        }
        b[i]=a[i];
    }
    if(b[n+1]!=0) printf("%d",b[n+1]); 
    for(int i=n;i>=1;i--)
    {
        printf("%d",b[i]);
    }
    return 0;
}