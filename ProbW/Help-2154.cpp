#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string s,s1;
struct zichuan
{
	string s2;
	int x;
}s2[10001];
bool huiwen(string a)
{
	int b=a.size();
	if(b<=1)
	{
		return true;
	}
	else
	{
		if(a[0]==a[b-1])
		{
			string x=a.substr(1,b-2);
			return huiwen(x);
		}
		else
		{
			return false;	
		}
	}
}
bool cmp(const zichuan&a,const zichuan&b)
{
	if(a.s2.size()==b.s2.size()) a.x<b.x;
	return a.s2.size()<b.s2.size();
}
int main()
{
	cin>>s;
	int a=s.size(),b,y=1;
	for(int i=0;i<a;i++)
	{
		for(int j=2;j<=a-i;j++)
		{
			s1=s.substr(i,j);
			if(s1.size()==1)
			{
				continue;
			}
			b=huiwen(s1);
			if(b!=0)
			{
				s2[y].s2=s1;
				s2[y].x=y;
				y++;
			}
		}
	}
	sort(s2+1,s2+1+y,cmp);
	for(int i=1;i<=y;i++)
	{
		printf("%s\n",s2[i].s2.c_str());	
	}
	return 0;
}
