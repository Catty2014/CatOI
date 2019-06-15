//SDOJ #1096 N皇后问题 #3695 n皇后
//Language:C++

#include<bits/stdc++.h>

int ans=0,n=0;
int a[30]={0},b[30]={0},c[50]={0};
int qwe;
int k[20]={0};

void qween(int x)
{
	//qwe++;
	for(int i=1; i<=n;i++)
	{
		//printf("%d:%d %d\n",qwe,x,i);
		if(a[i]==0&&b[i+x]==0&&c[i-x+20]==0)
		{
			k[x]=i;
			a[i]=1;
			b[i+x]=1;
			c[i-x+20]=1;
			if(x==n)
			{
				ans+=1;
				for(int j=1;j<=n;j++)
				{
					printf("%d ",k[j]);
				}
				printf("\n");
			}
			else
			{
			qween(x+1);
		    }
			a[i]=0;
			b[i+x]=0;
			c[i-x+20]=0;
		}
	}
	//qwe--;
}

int main()
{
 	scanf("%d",&n);
	qween(1);
	if (ans==0)
	{
		printf("no solute!");
		return 0;
	}
	printf("Total=%d",ans);
	return 0;
}
