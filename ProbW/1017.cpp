//SDOJ #1017 ÉñÆæFibonacciÊıÁĞ
//Language:C

#include <cstdio>


int main()
{
	int a1,a2,n;
	int t;
	scanf("%d %d %d",&a1,&a2,&n);
	for(int i=3;i<=n;i++)	
	{
		t=a1+a2;
		a1=a2;
		a2=t;
	}
	printf("%d",t);
	return 0;
}
