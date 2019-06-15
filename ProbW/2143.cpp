//SDOJ #2143 整数去重
//Language:C++
//Difficulty:Lv.0
//Method:VIOLENCE

#include<bits/stdc++.h>
using namespace std;

int num=1;
int a[52333];

int main ()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%d",&x);
		num++;
		int k=0;
		for(int j=1; j<=num; j++)
		{
			if (a[j]==x)
			{
				k=1;
				break;
			}
		}
		if(k==1) continue;
		else
		{
			a[i]=x;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i]==0) continue;
		printf("%d ",a[i]);
	}
	return 0;
}
