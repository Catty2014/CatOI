//SDOJ #1003 ÈÆ¶¤×ÓµÄ³¤Éþ
//C++

#include <cstdio>
#define PI 3.1415926
#include <cmath>

struct pp
{
	double x,y;
} p[110];

double dist(pp& a,pp& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int n=0;
double r=0.0;
int main()
{
	scanf("%d %lf",&n,&r);
	for(int i=1; i<=n; i++)
	{
		scanf("%lf %lf",&p[i].x,&p[i].y);
	//	printf("%lf %lf",p[i].x,p[i].y);
	}
	double sum=0.0;
	for(int i=2; i<=n; i++)
	{
		sum+=dist(p[i],p[i-1]);
	}
	sum+=dist(p[1],p[n]);
	sum+=2*PI*r;
	printf("%.2lf",sum);
	return 0;
}
