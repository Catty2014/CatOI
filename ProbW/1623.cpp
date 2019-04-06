//SDOJ #1623 ·ÖÀëÕûÊı
//C

#include<cstdio>

int digit(int m,int n);

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int ans;
	ans=digit(a,b);
	printf("digit(%d,%d)=%d",a,b,ans);
	return 0;
}

int digit(int m,int n)
{
	int d[8]= {0};
	int dig=1;
	int digi=0;
	for(int i=1; i<=8; i++)
	{
		d[i]=m%10;
		m=m/10;
		if(d[i]!=0&&m!=0) dig++;
	}
	return d[n];
}

