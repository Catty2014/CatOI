//SDOJ #1300 大象识数
//C

#include <stdio.h>


int main()
{
	int num=0;
	int n=0;
	int m=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		int ans=num;
		int digit=0;
		int numt=num;
		for(digit=1;;)
		{
			numt/=10;
			if (numt!=0)
			{
				digit++;
			}
			else
			{
				break;
			}
		}
		int digs=digit/2;
		//printf("%d ",digit);
		int digx=digit-digs;
		int L=0,R=0;
		int div=1;
		double k=0.1;
		for(int j=1;j<=digx;j++)
		{
			k = k*10;
			m = num%10;
			num=num/10;
			L = k*m+L;
		}
		for(int x=1;x<=digs;x++)
		{
			div=div*10;
		}
		R=(ans-L)/(div);
		//printf("%d %d",L,R);
		int Q=L+R;
		if (ans==Q*Q)
		{
			printf("%d\n",ans);
		}
		else
		{
			continue;
		}
	}
	return 0;
}
