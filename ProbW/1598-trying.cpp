//SDOJ #1598 魔法阵
//Luogu #2119 魔法阵
//Language:C++
//这是我的尝试 


#include <cstdio>
#include <algorithm>


struct magic{
	int id;
	int a,b,c,d;
	int srt;
	int xp;
}ma[40010];

bool cmp(const magic&a,const magic&b)
{
	return a.xp>b.xp;
}

int main()
{
	int m=0,n=0,s=0;
	scanf("%d %d",&n,&m);
	//int max=-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&ma[i].xp);
		//if(ma[i].xp>max) max=ma[i].xp;
		ma[i].id=i;
	}
	std::sort(ma+1,ma+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ma[i].srt=i;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i/9;j++)
		{
			for(int d=1;d<(i-j)/9;d++)
			{
				for(int k=1;k<=n;k++)
				{
				if(ma[k].xp==d)
				{
					int x=k
				}
				if(j+2*d==ma[k].xp) s++;
				if(ma[k].xp==i-k) s++;
				if (s==3) {
				ma[i].d++;
				ma[j]
				}
			}
		}
	}
	
	return 0;
}


