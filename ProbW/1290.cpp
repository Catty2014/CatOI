//SDOJ #1290 »»Æå×ÓÓÎÏ·
//Language:C++
//Difficulty:Lv.0
//Method:Common

#include <bits/stdc++.h>
using namespace std;

int a[10086]= {0};
int Count=0;
int ans=0;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i*i<=n; i++)
	{
		a[i]=i*i;
		ans++;
	}
	printf("%d\n",ans);
	for(int i=1; i*i<=n; i++)
	{
		if(a[i]!=0)
		{
			printf("%d ",a[i]);
			Count++;
			if(Count%5==0) printf("\n");
		}
	}
	return 0;
}


