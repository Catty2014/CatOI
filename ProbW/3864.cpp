//F♂A神AK各国
//x=x-(x-sqrt(x))
//↑这个操作有点骚
//Partically Finished

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using std::max;
using std::min;

const int N=1e5+233;
typedef long long ll;
int n,m;

struct SmT
{
    int l,r;
    ll lx,rx;
    ll tx,sum;
    int f;//???
}s[N<<2];//4 times space

int main()
{
    scanf("%d",&n);
    st_build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==1) 
    }
}