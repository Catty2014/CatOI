//SDOJ #2484 ÖÊÒòÊı
//C

#include <stdio.h>

int main()
{
	int num=0,n=0;
	scanf("%d",&num);
	for(int i=2; i<=num;)
	{
		if (num%i==0)
		{
			printf("%d ",i);
			n++;
			num=num/i;
		}
		else
		{
			i++;
		}
	}
	printf("\n%d",n);
	return 0;
}
