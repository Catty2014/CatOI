//SDOJ #1151 GREEN–€Œ∞µƒ…Ω∑ÂMAJESTY
//Language:C++
//Difficulty:Lv.2
//Method:GREEDY

#include <bits/stdc++.h>

using namespace std;

struct Mount
{
	int x,y;
	bool operator < (const Mount&p)const
	{
		if (x==p.x) return y<p.y;
		return x<p.x;
	}
}a[100086];

int n;

long long calc(int a,int b)
{
	return (b-a)*(b-a);
}

long long solve()
{
	int max_y=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].y<=max_y) continue;
		ans+=calc(a[i].x,a[i].y);
		if(a[i].x<max_y) ans-=calc(a[i].x,max_y);
		max_y=a[i].y;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1);
	long long ans=solve();
	printf("%d",ans);
	return 0;
}



