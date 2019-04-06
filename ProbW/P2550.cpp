#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

int a[9]={0};
int b[9];
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=7;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=7;i++)
        {
            int x;
            scanf("%d",&x);
            for(int i=1;i<=7;i++)
            {
                if (x==a[i]) ans++;
            }
        }
        b[ans]++;
        ans=0;
    }
    for(int i=7;i>=1;i--)
    {
        printf("%d ",b[i]);
    }
    return 0;
}

