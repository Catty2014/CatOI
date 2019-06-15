#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

int n;
int a[100133];
bool fail=0;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("disk.in","r",stdin);
        freopen("disk.out","w",stdout);
    #endif
    while(scanf("%d",&n)!=-1)//EOF==-1
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int _mn=min(a[1],a[2]);
        int _mx=max(a[1],a[2]);
        for(int i=3;i<=n;i++)
        {
            if(a[i]<_mx&&a[i]>_mn)
            {
                printf("J\n");
                fail=1;
                break;
            }
            if(a[i]<_mn) _mn=a[i];
            if(a[i]>_mx) _mx=a[i];   
        }
        if(!fail) printf("Y\n");
        fail=0;
    }
    return 0;
}