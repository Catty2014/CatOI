//SDOJ #3064 24µãÓÎÏ·
//Language:C++
//Method:VIOLENCE

#include <bits/stdc++.h>

int p[1000]= {0};
int q[1000]= {0};
int a[8];
int i;

int judge(int i,int j)
{
	if(i%6==1)
	{
		if(j%6==0) return 1;
	}
	if(i%6==2)
	{
		if(j%6==5) return 1;
	}
	if(i%6==3)
	{
		if(j%6==4) return 1;
	}
	if(i%6==4)
	{
		if(j%6==3) return 1;
	}
	if(i%6==5)
	{
		if(j%6==2) return 1;
	}
	if(i%6==0)
	{
		if(j%6==1) return 1;
	}
	return 0;
}

int judge2(int i,int j)
{
	if(i)
		if(i%4==1)
		{
			if(j==0) return 1;
		}
	if(i%4==2)
	{
		if(j==5) return 1;
	}
	if(i%4==3)
	{
		if(j==4) return 1;
	}
	if(i%4==0)
	{
		if(j==3) return 1;
	}
	return 0;
}

int judge3 ()
{
	scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
	p[1]=a[1]+a[2];
	p[2]=a[1]+a[3];
	p[3]=a[1]+a[4];
	p[4]=a[2]+a[3];
	p[5]=a[2]+a[4];
	p[6]=a[3]+a[4];
	p[7]=a[1]-a[2];
	p[8]=a[1]-a[3];
	p[9]=a[1]-a[4];
	p[10]=a[2]-a[3];
	p[11]=a[2]-a[4];
	p[12]=a[3]*a[4];
	p[13]=a[1]*a[2];
	p[14]=a[1]*a[3];
	p[15]=a[1]*a[4];
	p[16]=a[2]*a[3];
	p[17]=a[2]*a[4];
	p[18]=a[3]*a[4];
	p[19]=a[1]/a[2];
	p[20]=a[1]/a[3];
	p[21]=a[1]/a[4];
	p[22]=a[2]/a[3];
	p[23]=a[2]/a[4];
	p[24]=a[3]/a[4];
	/*for(int i=1; i<=24; i++)
	{
		printf("%d\n",p[i]);
	}*/
	for(int i=1; i<=24; i++)
	{
		for(int j=1; j<=24; j++)
		{
			if(judge(i,j)==0) continue;
			if(p[i]+p[j]==24)
			{
				
				return 0;
			}
			if(p[i]*p[j]==24)
			{
				
				return 0;
			}
			if (p[j]!=0) if(p[i]/p[j]==24)
				{
					
					return 0;
				}
			if(p[i]-p[j]==24)
			{
				
				return 0;
			}
		}
	}
	for(int i=1; i<=96; i++)
	{
		int tmp=i%4;
		if(tmp==0) tmp=4;
		q[i]=p[i/4]+a[tmp];
	}
	for(int i=1; i<=96; i++)
		for(int j=1; j<=4; j++)
		{
			if(judge2(i,j)==0) continue;
			if(q[i]+a[j]==24)
			{
				
				return 0;
			}
			if(q[i]*a[j]==24)
			{
				
				return 0;
			}
			if (a[j]!=0) if(q[i]/a[j]==24)
				{
					
					return 0;
				}
			if(q[i]-a[j]==24)
			{
				
				return 0;
			}
		}
	return 1;
}

int main()
{
	int ans[10086];
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		ans[i]=judge3();
	}
		for(int i=1; i<=n; i++)
	{
		if(ans[i]==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
