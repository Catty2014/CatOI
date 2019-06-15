//SDOJ #1289 【输入输出】数学计算
//C

#include <stdio.h>

int main (void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int s = 2*a*b+2*b*c+2*a*c;
	int v = a*b*c;
	printf("%d\n",s);
	printf("%d\n",v);
	return 0;
}
