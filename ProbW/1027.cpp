//SDOJ #1027 Êý×Ö½ÓÁ¦DIGIT
//C

#include <stdio.h>

int main()
{
	int num;
	scanf("%d",&num);
	printf("%d",num);
	int n=0,ans=1,numk=0,ed=0;
	for(;;)
	{
		n=num%10;
		num=num/10;
		ans*=n;
		if (num==0) 
		{
		 ed=1;	
		 break;
		}
		//printf(" %d %d ",ans,n);
	}
	printf(" %d",ans);
	if (ans<10) return 0;
	numk=ans;
	while(1)
	{
		for(;;)
		{
			if (ed==1)
			{
				ed=0;
				ans=1;
			}
			n=numk%10;
			numk=numk/10;
			ans*=n;
			//printf("ans=%d n=%d ",ans,n);
			if (numk==0) 
			{
				ed=1;
				printf(" %d",ans);
				if(ans<10) break;
				numk=ans;
				continue;
			}
			
		}
		if(ans<10) break;
	}
	return 0;
}
