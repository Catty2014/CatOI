//SDOJ #1525 ¹ºÎïÈ¯
//C

#include <stdio.h>

int main()
{
	int money;
	scanf("%d",&money);
	int n,ans;
	n = money/100;
	ans = money-22*n;
	printf("%d",ans);
	return 0;
}
