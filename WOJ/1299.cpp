//SDOJ #1299 Õª²ÝÝ®
//C

#include <stdio.h>

int main()
{
	int a=0,b=0;
	int n;
	for (int i=1;i<=10;i++)
	{
		scanf("%d",&n);
		if (n>=a) 
		{
			b = a;
			a = n;
		}
		else
		{
			if (n<a&&n>=b)
			{
				b = n;
			}
		}	
	}
	printf("%d",a*b);
	return 0;
} 
