//SDOJ #1293 Εά²½
//C

#include <stdio.h>

int main()
{
	int a,b,n,s;
	scanf("%d%d%d",&a,&b,&n);
	s = 2*a+b+n*2*(a+b);
	printf("%d",s);
	return 0;
}
