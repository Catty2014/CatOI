#include<bits/stdc++.h>
#define INF 1147483647
using namespace std;

int n,f[1333][1333],m[1333],L;
double NL;

struct Cow
{
	int x,y;
}a[233333];

double calc(const Cow&p,const Cow&q)
{
	return sqrt((double)(p.x-q.x)*(p.x-q.x)+(double)(p.y-q.y)*(p.y-q.y));
}

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);   /*Floyd Min Road*/
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]!=INF)
			{
				if(f[i][j]>m[i])
				{
					m[i]=f[i][j];
				}
				if(f[i][j]>L)
				{
					L=f[i][j];
				}
			}
		}
	}
}

void rd()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%1d",&x);
			if(x==1)
			{
				f[i][j]=calc(a[i],a[j]);
			}
			else
			{
				f[i][j]=INF;
			}
		}
	}
}

int main()
{
	rd();
	floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]==INF&&i!=j)
			{
				double t=calc(a[i],a[j])+m[i]+m[j];
				if(t<NL) NL=t;
			}
		}
	}
	if(L>NL) NL=L;
	printf("%.6lf\n",NL);
	return 0;
}
