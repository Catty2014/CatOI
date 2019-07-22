#include<bits/stdc++.h>
using namespace std;

const int fx[5]={0,-1,0,1,0};
const int fy[5]={0,0,1,0,-1};

int way[41][41],len=23333,n=0,m=0;
int Map[41][41];

void Go(int step,int x,int y)
{
	//cout<<step<<endl;
	int x1,y1;
	for(int i=1;i<=4;i++)
	{
		x1=x+fx[i];
		y1=y+fy[i];
		if(x1>=1&&x1<n&&y1>=1&&y1<=m&&way[x1][y1]==0&&Map[x1][y1]==0)
		{
			//cout<<x1<<" "<<y1<<endl;
			way[x1][y1]=1;
			printf("%d %d %d %d\n",n,m,x1,y1);
			if(x1==n&&y1==m)
			{
				if(step<len) len=step;
				//printf("%d ",len);
			}
			else
			{
				if(step+1<len) Go(step+1,x1,y1);
			}
			way[x1][y1]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&Map[i][j]);
		}
	}
	
	len=1000;
	memset(way,0,sizeof(way));
	
	way[1][1]=1;
	
	Go(2,1,1);
	if(len==1000)
	{
		printf("%d",-1);
	}
	else
	{
		printf("%d",len);
	}
	return 0;
}
