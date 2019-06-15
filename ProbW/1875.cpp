//SDOJ #1875 谁拿了最多奖学金
//C

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct sch{
	string name;
	int avg,cls;
	char gb,xb;
	int psg; 
	int sum;
}a[110];

bool cpr(const sch&x,const sch&y)
{
	return x.sum<y.sum;
}

int main()
{
	int num=0;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		cin>>a[i].name>>a[i].avg>>a[i].cls>>a[i].gb>>a[i].xb>>a[i].psg;
	}
	int total=0;
	for(int i=1;i<=num;i++)
	{
		if(a[i].avg>80&&a[i].psg>=1) a[i].sum+=8000;
		if(a[i].avg>85&&a[i].cls>80) a[i].sum+=4000;
		if(a[i].avg>90) a[i].sum+=2000;
		if(a[i].avg>85&&a[i].xb=='Y') a[i].sum+=1000;
		if(a[i].cls>80&&a[i].gb=='Y') a[i].sum+=850;
		total+=a[i].sum;
	}
	sort(a+1,a+num+1,cpr);
	cout<<a[num].name<<endl<<a[num].sum<<endl<<total;
	return 0;
}
 
