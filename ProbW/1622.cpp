//SDOJ #1622 max£¨a,b,c£©
//C

#include <stdio.h>

int max(int a,int b,int c)
{
	if (b>a) a=b;
	if (c>a) a=c;
	return a;
}

int main()
{
	int a=0,b=0,c=0;
	scanf("%d %d %d",&a,&b,&c);
	double x,y,z;
	double m;
	x = max(a,b,c);
	y = max(a+b,b,c);
	z = max(a,b,c+b);
	//printf("%d %d %d",a,b,c);
	m = x/(y*z);
	printf("%f",m);
	return 0;
}
