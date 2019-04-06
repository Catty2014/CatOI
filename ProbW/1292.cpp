//SDOJ #1292 ¥Ú”°Õº–Œ
//C

#include<stdio.h>

int main()
{
	int a,b,k;
	char n,m;
	scanf("%d %d %d %c",&a,&b,&k,&n);
	//scanf("%d",&k);
	//scanf("%c",&m);
	//scanf("%c",&n);
	switch(k)
	{
		case 1:
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++)
				{
					printf("%c",n);
				}
				printf("\n");
			}
			break;			
		case 2:
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=i-1;j++)
				{
					printf(" ");
				}
				for(int j=1;j<=b;j++)
				{
					printf("%c",n);
				}
				printf("\n");
			}
			break;
		case 3:
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=i;j++)
				{
					printf("%c",n);
				}
				printf("\n");
			}
			break;
	}
	return 0;
}
