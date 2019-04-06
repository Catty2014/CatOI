//SDOJ #1320 Ä¾¹÷Í¿É«
//Language:C++
//Difficulty:Lv.2
//Method:GREEDY

#include <bits/stdc++.h>

using namespace std;

int len[23333];
int ans=0;

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
	}
	sort(len+1,len+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		if(len[l]+len[r]<1000)
		{
			l++;r--;
		}
		else
		{
			r--;
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}
