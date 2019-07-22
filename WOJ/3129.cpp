//SDOJ #1011 ¼ÆÊýÅÅÐò
//C

#include <stdio.h>

long long a[10000]={0};

int main()
{
	int n=0,x=0,max=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
		if(x>max) max=x;
	}
	for(int i=0;;i++)
	{
		while(a[i]--)
		{
			printf("%d ",i);
		}
		if (i>=max) break;
	}
	return 0;
}
