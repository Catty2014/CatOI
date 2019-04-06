#include <bits/stdc++.h>
using namespace std;

int f[256][256],a[256][256];
int ans[256];

int mxt(int p,int q,int r)
{
	int tmp=(p)<(q)?(p):(q);
	return (tmp)<(r)?(tmp):(r);
}

/*Deep Dark Search*/
int dfs(int x,int y)
{
	if(x<=0||y<=0) return f[x][y]=0;
	if(f[x][y]!=-1)  return f[x][y];
	if(x<=1||y<=1) return f[x][y]=a[x][y];
	f[x][y]=mxt(dfs(x-1,y-1),dfs(x-1,y),dfs(x,y-1))+a[x][y];
	if(a[x][y]==0) return f[x][y]=a[x][y]=0;
	return f[x][y];
}

int main()
{
	memset(f,0xff,sizeof(f));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{scanf("%1d",&a[i][j]);
		//printf("%d %d\n",i,j);
		}
			
	}
	int tmp=dfs(n,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int p=f[i][j];p>=2;p--)
			{
				ans[p]++;
			}
		//printf("%d ",f[i][j]);
		}	
		//printf("\n");
	}
	for(int i=2;i<=n;i++)
	{
		if(ans[i]==0) return 0;
		printf("%d %d\n",i,ans[i]);
	}
	return 0;
}
