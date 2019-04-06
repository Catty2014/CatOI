//SDOJ #1519 ÅĞ¶ÏËØÊı
//C

#include <stdio.h>

int main()
{
	int num;
	scanf("%d",&num);
	for(int n=2;n<num;n++)
	{
		if (num%n==0)
		{
			printf("N");
			return 0;
		}
	}
	printf("Y");
	return 0;
} 
