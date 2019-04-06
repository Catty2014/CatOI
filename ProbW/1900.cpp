//SDOJ #1900 蚂蚁感冒
//Lang:Cpp
//Diff:Lv.2
//Mth:Emulate

#include <bits/stdc++.h>
using namespace std;

int n;
int a[55];

bool cmp (int a,int b)
{
	return abs(a)<abs(b);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	int tmp1=a[1];
	sort(a+1,a+n+1,cmp);
	int tmp2=0;
	for(int i=1; i<=n; i++)
	{
		if(a[i]==tmp1)
		{
			tmp2=i;
			break;
		}
	}
	int p=-100,q=100;
	if(a[tmp2]>0)
	{
		for(int j=tmp1+1; j<=n; j++)
		{
			if(a[j]<0)
			{
				q=a[tmp2];
				p=a[j];
				break;
			}
		}
		if(q==100) {q=a[tmp2];p=0;}
	}
	if(a[tmp2]<0)
	{
		for(int j=tmp1-1; j>=1; j--)
		{
			if(a[j]>0)
			{
				p=a[tmp2];
				q=a[j];
				break;
			}
		}
		if(p==-100) 
		{
		    p=a[tmp2];
		    q=0;
        }
	}
	int ans=0;
	//printf("%d %d",p,q);
	for(int i=1; i<=n; i++)
	{
		if(a[i]>=p&&a[i]<=q) ans++;
	}
	printf("%d\n",ans);
}
