//SDOJ #2050 ½øÖÆ×ª»»
//Language:C++
//Difficulty:Lv.0
//Method:Common

#include <bits/stdc++.h>
using namespace std;

char c[17]= {'0','1','2','3','4','5','6',
             '7','8','9','A','B','C','D','E','F'
            };

int a[23];

int main()
{
	int num,n;
	scanf("%d",&num);
	scanf("%d",&n);
	if(num<0) {
	printf("-");
	num=-num;}
	int i=1;
	while(num!=0)
	{
		a[i++]=num%n;
		num/=n;
		if(a[i]==0&&num==0)
		{
			i--;
			break;
		}

	}
	for(int j=i; j>=1; j--)
	{
		printf("%c",c[a[j]]);
	}
	return 0;
}
