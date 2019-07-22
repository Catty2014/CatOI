#include <stdio.h>

int main()
{
	int n,a1,a2,b1,b2,c1,c2;
	scanf("%d",&n);
	scanf("%d%d",&a1,&a2);
	scanf("%d%d",&b1,&b2);
	scanf("%d%d",&c1,&c2);
	int an,bn,cn;
	an = n/a1;
	if (n%a1!=0) an++;
	bn = n/b1;
	if (n%b1!=0) bn++;
	cn = n/c1;
	if (n%c1!=0) cn++;
	int am,bm,cm;
	am = an*a2;
	bm = bn*b2;
	cm = cn*c2;
	int min = am;
	if (bm<min) min = bm;
	if (cm<min) min = cm;
	printf("%d",min);
	return 0;
}
