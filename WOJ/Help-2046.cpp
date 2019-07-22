#include<bits/stdc++.h>
using namespace std;
struct student
{
	int num;
	string name;
	double money;
} a[12];
int main()
{
	double s=0,k=0;
	for(int i=1; i<=10; i++)
		cin>>a[i].num>>a[i].name>>a[i].money;
	for(int i=1; i<=10; i++)
		s+=a[i].money;
	k=s/10;
	for(int i=1; i<=10; i++)
		if(a[i].money>k)
		{
			cout<<a[i].num<<" "<<a[i].name;
			printf(" %.2lf\n",a[i].money);
		}
	return 0;
}
