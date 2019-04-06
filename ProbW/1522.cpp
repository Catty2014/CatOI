//SDOJ #1522 Êý×Öµ¹Ðò
//C

#include <stdio.h>

int main ()
{
	int num;
	scanf("%d",&num);
	int w,k,b,s,g,n4,n5,n6;
	w = num/10000;
	n4 = num%10000;
	k = n4/1000;
	n5 = n4%1000;
	b = n5/100;
	n6 = n5%100;
	s = n6/10;
	g = n6%10;
	printf("%d%d%d%d%d",g,s,b,k,w);
	return 0;
}
