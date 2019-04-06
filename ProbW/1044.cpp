//SDOJ #1044 ��ɫ������
//USACO Traing Section 1.1
//Lang:C++
//Difficulty:Lv.0
//Method:Common

/*
ID: 18111431
TASK: friday
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

int yyyy=1900,mm=1,dd=1;
int date=1;
int b[13];
int a[8];


int main()
{
	/* freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout); */
	int n;
	scanf("%d",&n);
	int ytar=yyyy+n-1;
	for(;;)
	{
		b[1]=31;
		dd++;
		if(dd>b[mm])
		{
			dd=1;
			mm++;
		}
		if(mm>12)
		{
			mm=1;
			yyyy++;
		}
		b[2]=28;
		if (yyyy%4==0||yyyy%400==0) b[2]=29;
		if (yyyy%100==0&&yyyy%400!=0) b[2]=28;
		b[1]=31;
		b[3]=31;
		b[5]=31;
		b[7]=31;
		b[8]=31;
		b[10]=31;
		b[12]=31;
		b[6]=30;
		b[4]=30;
		b[9]=30;
		b[11]=30;
		//printf("%d %d %d\n",yyyy,mm,dd);
		date++;
		if(yyyy>ytar) break;
		if(date>7) date-=7;//printf("%d\n",date);
		if(dd==13) a[date]++;
	}
	for(int i=6; i<=11; i++)
	{
		int k=i%7;
		if(k==0) k=7;
		printf("%d ",a[k]);
	}
	printf("%d",a[5]);
	return 0;
}
