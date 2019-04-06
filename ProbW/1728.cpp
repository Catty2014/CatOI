//SDOJ #1728 glodËáÄÌ¹¤³§
//C

#include <stdio.h>

int main()
{
	int c=0,s=0,t=99999,n=0,a=0,lst=0;
	long long ans=0;
	scanf("%d %d",&n,&s);
	for (int j=1;j<=n;j++)
	{
		scanf("%d %d",&c,&a);
		(c<t)?t=c:c=t;
		ans+=t*a;
		t=t+s;
	}
	printf("%lld",ans);
	return 0;
}
