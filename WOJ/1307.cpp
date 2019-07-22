//SDOJ #1307 ×Ö·ûËþ
//C

#include <stdio.h>

int main()
{
	int m=0,n=0,type;
	scanf("%d%d",&n,&m);
	if (m==0) type=64;
	else
	type=48;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		for (int j=1;j<=i;j++)
		{
			printf("%c",type+j);
		}
		for (int j=i-1;j>=1;j--)
		{
			printf("%c",type+j);
		}
		printf("\n");
	}
	return 0;
}
