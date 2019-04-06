//SDOJ #1042 Ð¡ X Êý×ÖÄ¸
//C

#include <stdio.h>

int main()
{
	int n=0,m=0;
	scanf("%d",&n);
	int l=0;
	int ans=0;
	int count=0;
	for (int i=0;i<=n;i++)
	{
		scanf("%c",&m);
		if (m==65)
		{
			count++;
		}
		else
		{
			if (ans<count)
			{
				ans = count;
				count = 0;
			}
			else
			{
				count = 0;
			}
		}
		l = m;
	}
	if (ans<count)
			{
				ans = count;
			}
	printf("%d",ans);
	return 0;
}
