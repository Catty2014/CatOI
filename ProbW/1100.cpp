//SDOJ #1100 ผฆอรอฌมý
//C 

#include <stdio.h>

int main()
{
	int h,f;
	int c,r;
	scanf("%d%d",&h,&f);
	r = (f-(2*h))/2;
	c = h-r;
	printf("%d %d",c,r);
	return 0;
}
