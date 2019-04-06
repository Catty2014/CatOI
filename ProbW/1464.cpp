//SDOJ #1464 求Hermite多项式的值
//Language:C++

#include <cstdio>

long long herm(int n,int x)
{
	if(n==0) return 1;
	if(n==1) return 2*x;
	return 2*x*herm(n-1,x)-2*(n-1)*herm(n-2,x);
}

int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	long long ans=0;
	ans=herm(n,x);
	printf("%lld",ans);
	return 0;
}
