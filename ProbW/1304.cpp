//SDOJ #1304 Òº¾§Êý×Ö
//Language:C++

#include <cstdio>

int a[30]={0}; 
char n;
int ans=1;

int main()
{
	int digmx=0,digmn=0;
	long long mx=0,mn=0;;
	for(int i=1; ;i++)
	{
		scanf("%c",&n);
		if(n==10) break;
		if(n==13) break;
		a[i]=n-48;
		
		switch(a[i])
		{
			case 0:
			ans*=2;
			digmx=8;
			digmn=0;
			break;
			case 1:
			ans*=3;
			digmx=7;
			digmn=1;
			break;
			case 2:
			ans*=2;
			digmx=8;
			digmn=2;
			break;
			case 3:
			ans*=3;
			digmx=9;
			digmn=3;
			break;
			case 4:
			ans*=2;
			digmx=9;
			digmn=4;
			break;
			case 5:
			ans*=4;
			digmx=9;
			digmn=5;
			break;
			case 6:
			ans*=2;
			digmx=8;
			digmn=6;
			break;
			case 7:
			ans*=2;
			digmx=7;
			digmn=3;
			break;
			case 8:
			ans*=1;
			digmx=8;
			digmn=8;
			break;
			case 9:
			ans*=2;
			digmx=9;
			digmn=8;
			break;	
		}
		mx=mx*10+digmx;
		mn=mn*10+digmn;
	}
	printf("%d\n%lld %lld",ans,mn,mx);
	return 0;
}
