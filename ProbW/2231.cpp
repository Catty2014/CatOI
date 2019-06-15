//然而并没有 树上修改2

#include <cstdio>

#define lb ((x)&(-x))

const int N=1e5+2333;

int n;
void _a(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lb;
    }
    return ;
}

int _q(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lb;
    }
    return ans;
}

int main()
{

}