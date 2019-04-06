#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

int a,b,x,y;

int extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    int _return =extgcd(b,a%b,x,y);
    int t=x;x=y;y=t-a/b*y;
    return _return;
}

int main()
{
    scanf("%d %d",&a,&b);
    extgcd(a,b,x,y);
    printf("%d\n",(x+b)%b);
    return 0;
}

