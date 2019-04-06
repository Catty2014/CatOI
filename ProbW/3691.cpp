#include<bits/stdc++.h>
using namespace std;

const int fx[5]= {0,2,1,-1,-2};
const int fy[5]= {0,1,2,2,1};

int way[233][233],len=23333,n,m,counter=0;

void Go(int step,int x,int y)
{
	int nx,ny;
	for(int i=0; i<=4; ++i)
	{
		//printf("%d %d\n",x,y);
		nx=x+fx[i];
		ny=y+fy[i];
		if((nx>=0)&&(nx<=m)&&(ny>=0)&&(ny<=n)&&(way[nx][ny]==0))
		{
			way[nx][ny]=1;
			if((nx==m)&&(ny==n))
			{
				if(step<len) len=step;
				counter++;
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

	scanf("%d%d",&m,&n);

	memset(way,0,sizeof(way));

	way[0][0]=1;

	Go(1,0,0);

	if(counter==0||len==23333)
		printf("%d",-1);
	else
	{
		printf("%d\n",len);
		printf("%d",counter);
	}
	return 0;
}
