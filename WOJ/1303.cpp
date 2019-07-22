//SDOJ #1303 数的因子
//C

#include <stdio.h>

int main()
{
	long num=0,n=0;
	scanf("%ld",&num);
	if (num%5==0&&!(num%10==0))
	{
		while(num%5==0)
		{
			n++;
			num = num/5;
		}
	}
	else
	{
		for (n=2;n<=num;n++)
		{
			if (num%n==0) break;	
		}	
	}
	printf("%ld",n);
	return 0;
}
