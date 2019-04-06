//SDOJ #1301 ·Ö×é
//C

#include <stdio.h>

int main()
{
	int m=0,n=0;
	int ma=0,fe=0;
	scanf("%d",&n);
	for(int i=-1;i<=n;i++)
	{
		scanf("%c",&m);
		if (m==77) ma++;
		if (m==70) fe++;
	}
	printf("%d %d",ma,fe);
	return 0;
} 
