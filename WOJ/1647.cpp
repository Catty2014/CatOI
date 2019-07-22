//SDOJ #1647 ½ðÒøµº
//Language:C++
//Difficulty:Lv.2
//Method:FREEZY

#include <bits/stdc++.h>

using namespace std;

struct metal
{
	double v;                                            //V:Value
	double m;                                            //M:Mass
}a[23333];

bool cmp(const metal&c,const metal&b)
{
	return c.v/c.m>b.v/b.m;
}

int kmt,wmx,wlf;
double ans=0;                                       //WLF:Weight LeFt

int main()
{
	int k=0;
	scanf("%d",&k);
	for(int i=1; i<=k; i++)
	{
		ans=0;
		scanf("%d %d",&wmx,&kmt);                        //WMX:Weight MaX |KMT:Kind of MeTal
		wlf=wmx;
		for(int j=1; j<=kmt; j++)
		{
			scanf("%lf %lf",&a[j].m,&a[j].v);
		}
		sort(a+1,a+kmt+1,cmp);
		for(int j=1; j<=kmt; j++)
		{
			if(wlf==0) break;
			if(wlf>=a[j].m)
			{
				wlf-=a[j].m;
				ans+=a[j].v*1.0;
				continue;
			}
			else
			{
				if(wlf>0&&wlf<a[j].m)
				{

					ans+=a[j].v/a[j].m*wlf*1.0;
					wlf=0;
					break;
				}
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
