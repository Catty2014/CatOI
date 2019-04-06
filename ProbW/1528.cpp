//SDOJ #1528 餐厅消费2
//C
//原型：#1527 餐厅消费1

#include <stdio.h>

int main()
{
	int mon,m,n;
	double mon1;
	scanf("%d",&mon);
	n = mon/100;
	if (mon%100>=68)
	{
		n = n+1;
		mon1 = n*68;
	}
	else
	{
	mon1 = mon-32*n;
    }
	double mon2 = mon*0.8;
	if (mon1>=mon2)
	{
		printf("%.2lf",mon2);
	}
	else
	{
		printf("%.2lf",mon1);
	}
}
