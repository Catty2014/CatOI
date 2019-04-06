//½×³Ë´úÂëºÏ¼¯
//Language:C++

#include <cstdio>

int fac(int n)
{
	int ans=0;
	if(n==1) return 0;
	ans=n*fac(n-1);
	return ans;
}

int fsum(int n)
{
	int sum=0;
	sum+=fac(n);
	return sum;
}
