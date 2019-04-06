//SDOJ #2007 »­¾ØÐÎ
//C

#include<stdio.h>

int main ()
{
	int a,b,t;
	char n;
	scanf("%d %d %c %d",&a,&b,&n,&t);
	for (int i=1;i<=a;i++)
	{
		if (i==1)
		{
		    for (int j=1;j<=b;j++)
		    {
	  	   	printf("%c",n);
	    	}
	    	printf("\n");
		}
		if (i==a)
		{
			for (int j=1;j<=b;j++)
			{
				printf("%c",n);
			}
		}
		if (i>1&&i<a)
		{
			printf("%c",n);
			for (int j=3;j<=b;j++)
			{
				if (t==0)
				{
			    	printf(" ");
				}
				else
				{
					printf("%c",n);
				}
			}
			printf("%c\n",n);
	}
	}
	return 0;
}
