//SDOJ #1634 �׳˺� 
//C

#include <stdio.h>

long long fac(int n)
{
	long long ans=1;
	for(int i=1; i<=n; i++)
	{
		ans*=i;
	}
	return ans;
}

long long facsum(int m)
{
	long long sum=0;
	for(int j=1; j<=m; j++)
	{
		sum+=fac(j);
	}
	return sum;
}

int facsum2(int p)
{
	int q=0;
	int sum=0;
	for(int k=1; k<=p; k++)
	{
		sum+=fac(k);
		if(sum%10==0)
		{
			sum=sum/10;
			q++;
		}
		if(sum>=1E10)
		{
			sum=sum%10;
		}
	}
	return sum;
}

int main()
{
	int num;
	scanf("%d",&num);
	long long ans1=0;
	ans1=facsum(num);
	printf("%lld",ans1);
	return 0;
}
