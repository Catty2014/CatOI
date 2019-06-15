//SDOJ #1509 ÕÒÊ÷¸ùºÍº¢×Ó
//Language:C++
//Difficulty:Lv.2
//Method:Common

#include <bits/stdc++.h>
using namespace std;

int a[233],b[233],child[233][233],Count[233],root[233];
int MaxID;

int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(root[a[i]]!=-1)
		{
			root[a[i]]=1;
		}
		root[b[i]]=-1;
		Count[a[i]]++;
		child[a[i]][i]=b[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(root[i]==1)
		{
			printf("%d\n",i);
		}
	}
	int Max=0;
	for(int i=1; i<=n;i++)
	{
		if(Max<Count[a[i]])
		{
			Max=Count[a[i]];
			MaxID=a[i];
		}
	}
	printf("%d\n",MaxID);
	for(int i=1;i<=n;i++)
	{
		if(child[MaxID][i]) printf("%d ",child[MaxID][i]);
	}
	return 0;
}
