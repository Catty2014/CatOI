//SDOJ #1855 ½±Ñ§½ð
//Language:C++

#include <cstdio>
#include <algorithm>

using namespace std;

struct scol
{
	int id;
	int ch;
	int total;
} a[10086];

bool comp(const scol&a,const scol&b)
{
	if(a.total==b.total && a.ch==b.ch) return a.id<b.id;
	if(a.total==b.total) return a.ch>b.ch;
	return a.total>b.total;
}

int mt,en,ch;

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&ch,&mt,&en);
		a[i].id=i;
		a[i].total=ch+mt+en;
		a[i].ch=ch;
	}
	sort(a+1,a+n+1,comp);
	for(int i=1;i<=5;i++)
	{
		printf("%d %d\n",a[i].id,a[i].total);
	}
	return 0;
}
