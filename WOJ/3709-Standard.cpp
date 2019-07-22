//SDOJ #3709 进制转换二进制转十进制
//Language:C++
//Difficulty:Lv.0
//STANDARD ANSWER

/* 
After Tons of Try....
....
Dead In 3709...

Can Anybody Tell Me why???
I gonna die here...
*/

#include<bits/stdc++.h>
using namespace std;

string a;

long long calc(string &a)
{
	int lenth=a.size();
	long long ans=0,t=1;
	for(int i=lenth-1;i>=0;i--)
	{
		if(a[i]==49)
		ans+=t;
		t*=2;
	}
	return ans;
}

int main()
{
	cin>>a;
	long long ans=calc(a);
	printf("%lld",ans);
	return 0;
}
