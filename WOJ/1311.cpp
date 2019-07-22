//SDOJ #1311 Êý¸ù
//C

#include <stdio.h>

int main()
{
	int num=0,m=0,n=0,sum=0,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%1d",&m);
		//printf("m=%d\n",m);
		sum=sum+m;
		//printf("sum=%d\n",sum);
	}

	{	
	for (;sum>=10;)
	{
		while(sum)
		{
			//printf("This is Cycle 22222");
			n=sum%10;
			sum=sum/10;
			ans=ans+n;
			//printf("ans=%d sum=%d\n",ans,sum);
		}
		//printf("This is Cycle 11111");
	}
	}
	if (sum<10&&ans==0) ans = sum;
	if (ans>=10)
	{
		sum = ans;
		ans = 0;
		for (int i=1;i<=2;i++)
		{
			n=sum%10;
			sum=sum/10;
			ans=ans+n;		
		}
	}
	printf("%d",ans);
	return 0;
}
