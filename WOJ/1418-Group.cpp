//SDOJ #1418 ø®∆¨”Œœ∑
//Language:C++
//Difficulty:Lv.1
//Method:Group

#include <bits/stdc++.h>
using namespace std;
int n,c[23333],fro,bot;
int main()
{
	scanf("%d",&n);
	fro=1,bot=n+1;
	for(int i=1;i<=n;i++)
	{
		c[i]=i;
	}
	while(fro!=bot)
	{
		printf("%d ",c[fro++]);
		if(fro!=bot)
		{
			c[bot++]=c[fro++];
		}
	}
	return 0;
}
