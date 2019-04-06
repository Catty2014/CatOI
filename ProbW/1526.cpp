//SDOJ #1526 求正方体的表面积和体积
//C

#include <stdio.h>

int main ()
{
	int a,s,v;
	scanf("%d",&a);
	s = 6*a*a;
	v = a*a*a;
	printf("%d\n%d",s,v);
	return 0;
}
