//SDOJ #1021 �Ŷӽ�ˮ
//C

#include <cstdio>
#include <algorithm>

using namespace std;

struct water
{
	int time,sort;
} a[10010];

bool cpr(const water&a,const water&b)
{
	//printf("I am running!!!\n");
	return a.time<b.time;

}

int main()
{
	int n;         //����
	scanf("%d",&n);
	double ttl=0;
	double avg=0;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i].time);
		a[i].sort=i;
	}
	sort(a+1,a+n+1,cpr);
	for(int i=1; i<=n; i++)
	{
		printf("%d ",a[i].sort);          //������� 
	}
	for(int i=1; i<=n; i++)
	{
		ttl+=(a[i].time)*(n-i);          //����ƽ��ֵ 
	}
	avg=ttl/n;
	printf("\n%.2lf",avg);
	return 0;
}
