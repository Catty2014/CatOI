//SDOJ #1793 ½ð±Ò
//C

#include <stdio.h>

int main()
{
	int d=0,a=1,p=1,t=0,dt=0;
	scanf("%d",&dt);
	for (int d=1;1==1;d++)
	{
		t = p+t;
		if (d==dt) break;
		if (d==a)
		{
			a = p+a+1;
			p = p+1;
		}
	}
	printf("%d",t);
	return 0;
}
