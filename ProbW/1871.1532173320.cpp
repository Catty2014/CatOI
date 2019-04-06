//SDOJ #1871 лулуу╙ф╩╧Ш
//C

#include <stdio.h>

int main()
{
	int h[11]={0};
	int l=0,ans=0;
	for(int i=1;i<=10;i++)
	{
		scanf("%d",&h[i]);
	}
	scanf("%d",&l);
	l+=30;
	for(int j=1;j<=10;j++)
	{
		if (h[j]<=l) ans++;
	}
	printf("%d",ans);
	return 0;
}
