//SDOJ #1294 Õ¡∂π
//C

#include <stdio.h>

int main()
{
	int n,a,max=0;
	scanf("%d",&n);
	for (int n1=0;n1<n;n1++)
	{
		scanf("%d",&a);
		if (max<a) max = a;
	}
	printf("%d",max);
	return 0;
}
