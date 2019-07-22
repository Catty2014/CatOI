//SDOJ #1279 ORANGE-ISBN
//Language:C++
//Difficulty:Lv.0
//Method:Common

#include<bits/stdc++.h>

using namespace std;

int a[13];
char x;
int lost=0;
int s=0;
int ansext=0;

int main()
{
	for(int i=1; i<=10; i++)
	{
		scanf("%c",&x);
		if(x=='X') a[i]=10;
		if(x=='?')
		{
			a[i]=0;
			lost=i;
		}
		if(x>=48&&x<='9') a[i]=x-48;
	}
	for(int i=1; i<=10; i++)
	{
		s+=(11-i)*a[i];
	}
	int ans=0;
	for(ans=0; ans<=10; ans++)
	{
		if((s+ans*(11-lost))%11==0)
		{
			ansext=1;
			break;
		}
	}
	if(ansext==1)
	{
		if(ans==10)
		{
			if(lost==10)
			{
				printf("X");
				return 0;
			}
		}
		else
		{
			printf("%d",ans);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
