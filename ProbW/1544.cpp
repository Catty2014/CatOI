//SDOJ #1544 ×ª»»Ê±¼ä
//C

#include <stdio.h>

int main()
{
	int t,h,m,s;
	int t1,t2;
	scanf("%d",&t);
	t1 = t%3600;
	t2 = t1%60;
	h = t/3600;
	m = t1/60;
	s = t2;
	printf("%d:%d:%d",h,m,s);
	return 0;
}
