//SDOJ #1310 ×Ö·û²éÕÒ
//Language:C+
//Difficulty:Lv.0
//Method:Common

#include <bits/stdc++.h>
using namespace std;

char s[266];
char c;
int order,counter;

int main()
{
	cin.getline(s,256);
	cin>>c;
	for(int i=0; i<=strlen(s); i++)
	{
		if(s[i]==c)
		{
			if(order==0) order=i+1;
			counter++;
		}
	}
	printf("%d %d",order,counter);
	return 0;
}
