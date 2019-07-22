//SDOJ #1520 计算各个数字之和
//C

#include <stdio.h>

int main ()
{
	int num;
	scanf("%d",&num);
	int kw,bw,sw,w,k,b,s,g,n1,n2,n3,n4,n5,n6,sum;
	kw = num/10000000;
	n1 = num%10000000;
	bw = n1/1000000;
	n2 = n1%1000000;
	sw = n2/100000;
	n3 = n2%100000;
	w = n3/10000;
	n4 = n3%10000;
	k = n4/1000;
	n5 = n4%1000;
	b = n5/100;
	n6 = n5%100;
	s = n6/10;
	g = n6%10;
	sum = kw+bw+sw+w+k+b+s+g;
	printf("%d",sum);
	return 0;
}
