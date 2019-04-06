//SDOJ #1309 Ñ¡¾Ù
//C

#include <stdio.h>

int main()
{
	int n=0,x=0;
	int a=0,b=0,c=0;
	scanf("%d",&n);
	for (int i = 1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x==1) a++;
		if (x==2) b++;
		if (x==3) c++;
	}
	if (b>a&&b>c) printf("2");
	if (c>a&&c>b) printf("3");
	if (a>c&&a>b) printf("1");
	return 0;
}
