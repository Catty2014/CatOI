#include <bits/stdc++.h>
using namespace std;

struct Mtp{
	int x,y;
}a[233];

int f[233][233],n;

int dfs(int i,int j)
{
	if(f[i][j]!=-1) return f[i][j];
	if(i==j) return 0;
	f[i][j]=2133333333;
	for(int k=i;k<j;k++)
	{
		f[i][j]=min(f[i][j],dfs(i,k)+dfs(k+1,j)+a[i].x*a[k].y*a[j].y);
	}
	return f[i][j];
}

int main()
{
	memset(f,0xff,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i+n]=a[i];
	}
	int ans=2133333333;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dfs(i,n+i-1));
	}
	printf("%d\n",ans);
}
