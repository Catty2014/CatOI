//SDOJ #1546 a³ýÒÔb
//C

#include <cstdio>

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
	int num=0,div=0;
	int x,m,t=0;
	scanf("%d%d",&num,&div);
	x=num/div;
	m=num%div;
	printf("%d.",x);
	for (int i=1;i<=35;i++)
	{
        m*=10;
		t = m/div;
        m%=div;
		printf("%d",t);		
	}
	return 0;
}
