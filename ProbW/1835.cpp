//SDOJ #1835 ЛњЦїЗ­вы
//Language:C++
//Difficulty:2
//Method:Group

#include <bits/stdc++.h>
using namespace std;

int w[23333];
int m[2333],st=1,ed=0;
int memused;
int k=0;
int ans=0;

int main()
{
	int ms,plt;
	scanf("%d %d",&ms,&plt);
	for(int i=1;i<=plt;i++)
	{
		scanf("%d",&w[i]);	
	}
	for(int i=1;i<=plt;i++)
	{
		k=0;
		//printf("%d\n",w[i]);
		for(int j=st;j<=ed;j++)
		{
			if(m[j]==w[i]) 
			{
				//i++;
				k=1;
				break;
			}
		}
		if(k==1) continue;
		if(memused==ms)
		{
			st++;
			memused--;
		}
		//printf("%d %d\n",st,ed);
		m[++ed]=w[i];
		ans++;
		memused++;
	}
	printf("%d",ans);
	return 0;
}
