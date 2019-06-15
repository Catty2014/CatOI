#include<bits/stdc++.h>
using namespace std;
int n,m,s=0,Max=-1,a[101][101]= {0},way[101][101]= {0};
int dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0};
void yongchi(int f,int x,int y)
{
	int k=f;
	if(k==0) return;
	way[x][y]=1;
	s++;
	f=0;
	int nx,ny;
	for(int i=0; i<=3; i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&way[nx][ny]==0&&a[nx][ny]==k)
		{
			printf("%d %d\n",nx,ny);
			yongchi(k,nx,ny);

			continue;
		}
	}
	if(Max<s) Max=s;
	cout<<Max<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			yongchi(a[i][j],i,j);
			s=0;
		}
	}
	cout<<endl<<Max;
	return 0;
}
