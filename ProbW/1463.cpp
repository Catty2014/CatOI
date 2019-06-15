//SDOJ #1463 ¿ªµÆÎÊÌâ
//C

#include <stdio.h>

int main()
{
	int a[1001]={0};
	int n=0;
	int k=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n/i;j++)
		{
		a[j*i]=!a[j*i];
		//printf("i:%d ",a[j*i]);
		}
		//printf("\n");
	}
	for(int l=1;l<=n;l++)
	{
		if (a[l]==1) printf("%d ",l);
	}
	return 0;
}

