#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

long long x,y,l,n,m;

long long extgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    else
    {
        long long ret=(extgcd(b,a%b,x,y));
        long long t=x;x=y;y=t-(a/b)*y;
        return ret;
    }
}

/*
    假设{x1,y1},{x2,y2}是方程的解
    则:
	ax1+by1=c  ---A
	ax2+by2=c  ---B
    A-B:
	a(x1-x2)+b(y1-y2)=0;
    令 d=gcd(a,b)
	(a/d)(x1-x2)+(b/d)(y1-y2)=0
    此时，a/d与b/d互质，则:
	x1-x2=(b/d)(y2-y1)/(a/d)=k*(b/d),(k belongs to N*)
    通解：
	x=x0+k(b/d)
    所以，最小正整数解:
	x=(x0 % (b/d)+ b/d) % (b/d)
*/
inline long long solve(long long a,long long b,long long c)
{
    long long d=extgcd(a,b,x,y);
    if(c%d) return -1;
    x=x*c/d;
    x=(x%b+b)%b;
    return x;
}
int main()
{
    scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l);
    long long ans=solve(n-m,l,x-y);
    if(ans==-1) printf("Impossible\n");
    else
    printf("%lld\n",ans);
    return 0;
}

