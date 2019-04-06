//SDOJ #1322 整数区间
//Language:C++
//Difficulty:Lv.1
//Method:GREEDY

#include <bits/stdc++.h>                //All-can-do Library

using namespace std;

struct space{
	int S,F;
}a[10001];

bool cmp(const space&a,const space&b)
{
	if(a.S==b.S) return a.F<b.F;
	return a.S<b.S;
}

int main()
{
	int n,b[10001]={0},k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].S,&a[i].F);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		int f=0;
		for(int j=a[i].S;j<=a[i].F;j++)
		{
			if(b[j]==1)
			f++;
		}
		if(f==0)
		{
			b[a[i].S]=1;
			k+=1;
		}
	}
	cout<<k;
	return 0;
}
