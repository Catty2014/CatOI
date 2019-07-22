//SDOJ #2046 账户查询(结构体的应用)
//C

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct ac{
	int account;
	string name;
	double money;
}a[12];

int main()
{
	for(int i=1;i<=10;i++)
	{
		cin>>a[i].account;
		cin>>a[i].name;
		cin>>a[i].money;
	}
	double var=0;
	for(int i=1;i<=10;i++)
	{
		var+=a[i].money;
	}
	var/=10;
	for(int i=1;i<=10;i++)
	{
		if(a[i].money>=var)
		{
			printf("%d ",a[i].account);
			cout<<a[i].name<<" ";
			printf("%.2lf\n",a[i].money);
		}
	}
	return 0;
}
