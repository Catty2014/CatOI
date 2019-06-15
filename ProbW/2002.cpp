//SDOJ #2002 输出最大数
//C

#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if (b>a) a = b;
	if (c>a) a = c;
	printf("%d",a);
} 
