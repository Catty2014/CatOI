//SDOJ #1821 Êý×Ö·´×ª
//C

#include <stdio.h>
#define sf(x) scanf("%1d",&x)
#define pf(x) printf("%d",x)

int main()
{
	int num=0,ans=0,m=0;
	scanf("%d",&num);
	for (;num!=0;)
	{
		m=num%10;
		num=num/10;
		//pf(ans);
		ans=ans*10+m;
	}
	pf(ans);
	return 0;
}
