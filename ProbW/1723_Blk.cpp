#include <cstdio>
#include <algorithm>
#include <cmath>

using std::sqrt;
using std::min;
const int N=102333;

int a[N],v[N],b[N];
int n,m,k;

void _add(int x,int y,int z)
{
    for(int i=x;i<=min(b[x]*k,y);i++)//first
    {
        v[i]+=z;
    }
    if(b[x]!=b[y])
    {
        for(int i=(b[y]-1)*k+1;i<=y;i++)//last
        {
            v[i]+=z;
        }
    }
    for(int i=b[x]+1;i<=b[y]-1;i++)
    {
        a[i]+=z;//lazy add
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    k=sqrt(n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) b[i]=(i-1)/k+1;
    for(int i=1;i<=m;i++)
    {
        int f,x,y,z;
        scanf("%d",&f);
        if(f==1)
        {
            scanf("%d %d %d",&x,&y,&z);
            _add(x,y,z);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",v[x]+a[b[x]]);
        }
    }
    return 0;
}