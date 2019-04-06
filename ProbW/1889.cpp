//SDOJ #1889 级数求和
//Language:C++
//Difficulty:Lv.0
//Method:Common

#include <bits/stdc++.h>

int main()
{
	double S=0;
	int k=0;
	scanf("%d",&k);
	int num=0;
	for(;S<=k;)
	{
		num+=1;
		S=S*1.0+1.0/num;
		//printf("%lf\n",S);
	}
	printf("%d",num);
	return 0;
}
