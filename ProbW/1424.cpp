#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll f[44][44];
ll num[44][44];
char str[42];

int main()
{
	int i,j,k,l,n;
	scanf("%d %d",&n,&k);
	scanf("%s",&str[1]);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			num[i][j]=num[i][j-1]*10+str[j]-'0';
		}
	}
	for(i=1;i<=n;i++)
	{
		
	}
	return 0;
}
