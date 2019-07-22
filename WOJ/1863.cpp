//SDOJ #1863 明明的随机数
//Language:C++

#include <cstdio>

int a[10086]={0};

int main()
{
	int m=0,n=0,x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(a[x]==0) m++;
		a[x]++;
	}
	printf("%d\n",m);
	for(int i=1;i<=1001;i++)
	{
		if(a[i]!=0)
		{
			printf("%d ",i);		
		}
	}	
	return 0;
}
