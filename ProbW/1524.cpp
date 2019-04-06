//SDOJ #1524 ·ÖÌÇ¹û1
//C

#include <stdio.h>

int main()
{
	int a1,a2,a3,a4,a5;
	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
	a2 = a1/3+a2;
	a5 = a1/3+a5;
	a1 = a1/3;
	a1 = a2/3+a1;
	a3 = a2/3+a3;
	a2 = a2/3;
	a2 = a3/3+a2;
	a4 = a3/3+a4;
	a3 = a3/3;
	a3 = a4/3+a3;
	a5 = a4/3+a5;
	a4 = a4/3;
	a4 = a5/3+a4;
	a1 = a5/3+a1;
	a5 = a5/3;
	printf("%d %d %d %d %d",a1,a2,a3,a4,a5);
	return 0;
}
