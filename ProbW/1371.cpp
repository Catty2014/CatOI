//SDOJ #1371 回文质数 Prime Palindromes
//C

#include <cstdio>

bool prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

/*bool palindrome(int n)
{
	int ord=0;
	ord=n;
	int m,diso=0,k=1;
	while(n)
	{
		m=n%10;
		n=n/10;
		diso=diso*10+m;
		//printf("diso=%d\nn=%d",diso,n);
	}
	if(diso==ord) return true;
	return false;
}*/

long long pal(int n)
{
	long long ans=n;
	n=n/10;
	while(n>0)
	{
		ans=ans*10+n%10;
		n=n/10;
	}
	return ans;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	//int nk=0;
	//freopen("out","w",stdout);
	int l=0,r=0;
	int a=0,b=0;
	scanf("%d %d",&l,&r);
	if(l<12)
	{
		for(int i=l; i<12; i++)
		{
			if(prime(i)==true)
			{
				write(i);
				printf("\n");
			}
		}
	}
	for(int i=10;;i++)
	{
		int num=0;
		num=pal(i);
		if(num<l) continue;
		if(num>r) break;
		//printf("num=%d\n",num);
		if(prime(num)==true)
		{
			write(num);
			printf("\n");
			//nk++;
		}
	}
	//printf("total %d numbers",nk);
	return 0;
}
