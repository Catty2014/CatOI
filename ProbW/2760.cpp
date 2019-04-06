#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int num,maxnum=0,maxcache=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        /* debug(ans); */
        if(num==maxnum) maxcache+=num;
        if(num>maxnum)
        {
            maxnum=num;
            ans+=maxcache;
            maxcache=num;
        }
        if(num<maxnum)
        {
            ans+=num;
        }
    }
    printf("%d\n",ans);
    return 0;
}

