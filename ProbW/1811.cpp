//SDOJ #1811 质因数分解
//C

#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a=0,b=0;
	for (a=2;a<=n;a++)
	{
		if (n%a==0) break;
	}
	b = n/a;
	printf("%d",b);
	return 0;
}
