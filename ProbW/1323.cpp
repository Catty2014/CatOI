#include <bits/stdc++.h>
using namespace std;

int n;
int f[233][233];
int s[10086];

int dfs(int l,int r)
{
	//printf("Here!\n");
	if(l==r) return f[l][r]=0;
	if(f[l][r]!=-1) return f[l][r];
	int ans=0x7fffffff;
	for(int k=l;k<r;k++)
		ans=min(ans,dfs(l,k)+dfs(k+1,r));
	f[l][r]=ans+s[r]-s[l-1];
	return f[l][r];
}

int main()
{
	scanf("%d",&n);
	//l=1;r=n;
	memset(f,0xff,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		s[i]+=s[i-1];
	}
	printf("%d",dfs(1,n));
	return 0;
}
