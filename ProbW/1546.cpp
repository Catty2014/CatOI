//SDOJ #1546 a除以b
//C
//完成中 

#include <cstdio>

int main()
{
	int num=0,div=0;
	int x,m,t;
	scanf("%d%d",&num,&div);
	x=num/div;
	m=num%div;
	printf("%d.",x);
	
	for (int i=1;i<=35;i++)
	{
		div = div*10;
		t = m/div;
		printf("%d",t);		
	}
	return 0;
}
