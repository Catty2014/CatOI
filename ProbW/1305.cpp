//SDOJ #1305 ÕûÊı³ı
//C

#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	(a%b==0)?printf("%d",a/b):printf("%d  %d",a/b,a%b);
	return 0;

}
