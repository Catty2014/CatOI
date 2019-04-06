//SDOJ #1379 √‘π¨Œ Ã‚
//Language:C++

#include<bits/stdc++.h>
using namespace std;

const int fx[5]= {0,-1,0,1,0};
const int fy[5]= {0,0,1,0,-1};

int way[22][22],len,n,m;
int Map[22][22];
int ans=0;

void Go(int step,int x,int y)
{
	int nx,ny;
	for(int i=1; i<=4; i++)
	{
		nx=x+fx[i];
		ny=y+fy[i];
		if((nx>=1)&&(nx<=n)&&(ny>=1)&&(ny<=m)&&(way[nx][ny]==0)&&(Map[nx][ny]==0))
		{
			way[nx][ny]=1;
			if((nx==n)&&(ny==m))
			{
				ans++;
			}
			else Go(step+1,nx,ny);
			way[nx][ny]=0;
		}
	}
}

int main()
{
	//freopen("maze.in","r",stdin);
	//freopen("maze.out","w",stdout);

	scanf("%d%d",&n);
	m=n;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&Map[i][j]);

	len=1000;
	memset(way,0,sizeof(way));

	way[1][1]=1;

	Go(2,1,1);

	if(len==1000)
		printf("%d",-1);
	else
		printf("%d",len);
	return 0;
}
