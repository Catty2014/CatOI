//SDOJ #3709 进制转换二进制转十进制
//Language:C++
//Difficulty:Lv.0
//Method:Common

/* 
After Tons of Try....
....
Dead In 3709...

Can Anybody Tell Me why???
I gonna die here...
*/

#include<bits/stdc++.h>
using namespace std;

long long k=1;
long long ans=0;
int a[50]= {0};
char x;

int main()
{
	int i=1;
	while(1)
	{
		scanf("%c",&x);
		if(x==10) break;
		a[i]=0;
		if(x==49) a[i]=1;
		i++;
	}
	for(int j=i-1; j>=1; j--)
	{
		ans+=a[j]*k;
		k*=2;
	}
	printf("%lld",ans);
	return 0;
}
