//SDOJ #1418 ø®∆¨”Œœ∑
//Language:C++
//Difficulty:Lv.1
//Method:Common

#include<bits/stdc++.h>

int a[233],head,bottom;
int b[233];

int main()
{
	int n;
	scanf("%d",&n);
	int num=n;
	for(int i=1; i<=n; i++)
	{
		a[i]=i;
	}
	for(int i=1; num>=2; i++)
	{
		b[i]=a[1];
		a[1]=0;
		for(int j=2; j<=n; j++)
		{
			a[j-1]=a[j];
		}
		if(num==1) break;
		a[n-i+1]=a[1];
		for(int j=2; j<=n; j++)
		{
			a[j-1]=a[j];
		}
		num--;
	}
	for(int i=1; i<=n-1; i++)
	{
		printf("%d ",b[i]);
	}
	printf("%d",a[1]);
	return 0;
}
