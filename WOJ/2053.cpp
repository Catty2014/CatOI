//SDOJ #2053 ��ȡ����
//C

#include <stdio.h>

int main()
{
	long long num0,numans=0,n=0,x=0;
	double k=0.1;
	scanf("%lld",&num0);
	while(num0!=0)
	{
		n=num0%10;
		num0=num0/10;
		if (n%2!=0)
		{
			k = k*10;
			numans = k*n+numans;
		}
	}
	printf("%lld",numans);
}
