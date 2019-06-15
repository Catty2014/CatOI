//测验1113 题目2 #3679 统计
//Language：C++

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int x[600]={0};
	double sum=0;
	double avg=0;
	double mid=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",x[i]);
		sum+=x[i];
	}
	avg=sum/n;
	sort(x+1,x+n+1);
	if(n%2==1)
	{
		printf("%d",x[(n/2)+1]);
	}
	else
	{
		mid=x[(n/2)]+x[(n/2)+1];
		mid/=2;
		printf("%d",mid);
	}
	return 0;
}
