//SDOJ #2001 三角形问题
//C

#include <stdio.h>

int main()
{
	int a,b,c;
	int valid,aleq,aeq;
	scanf("%d%d%d",&a,&b,&c);
	if (a+b<=c||a+c<=b||b+c<=a)
	{
		printf("NO!");
	} 
	else
	{
		if ((a==b)&&(b==c))
		{
			printf("deng bian sanjiaoxing");
		}
		else
		{
			if ((a==b)||(b==c))
			{
				printf("deng yao sanjiaoxing");
			}
			else
			{
				printf("yi ban sanjiaoxing");
			}
		}
	}
} 
