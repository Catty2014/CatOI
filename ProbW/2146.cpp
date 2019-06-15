//SDOJ #2146 ¹ÍÓ¶±ø
//C

#include<stdio.h>

int main()
{
	int m=0,n=0,x=0,t=0;
	scanf("%d%d%d",&m,&n,&x);
	while(1)
	{
		if(x>0)
		{
		if(m%n==0)
		{
			x-=m/n;
		}
		else
		{
			x-=m/n+1;
		}
		//printf("x=%d t=%d\n",x,t);
		if (x>=0) n+=m/n;
		}
		else
		{
			break;
		}
	}
	printf("%d",n);
	return 0;
}
