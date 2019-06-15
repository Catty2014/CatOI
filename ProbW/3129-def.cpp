//SDOJ #3129 ÅÅÐòÄ£°å
//C

#include <stdio.h>
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d ",x)

int a[10001];

int main()
{
	int n=0,x=0;
	sf(n);
	for(int i=1;i<=n;i++)
	{
		sf(x);
		a[x]++;
	}
	for(int i=0;i<=10000;i++)
	{
		while(a[i]--)
		{
			pf(i);
		}
	}
	return 0;
}
