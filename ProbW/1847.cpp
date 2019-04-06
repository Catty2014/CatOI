//SDOJ #1847 ISBNºÅÂë
//Language:C++

#include <bits/stdc++.h>

int main()
{
	int a,b,c,d,e,f,g,h,i,s=0;
	int sum=0,k=0;
	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1c",
	      &a,&b,&c,&d,&e,&f,&g,&h,&i,&s);
	sum=a+b*2+c*3+d*4+e*5+f*6+g*7+h*8+i*9;
	k=sum%11;
	//printf("%d\n",s);
	if(s=='X')
	{
		s=10;
	}
	else
	{
		s-=48;
	}
	if(s==k)
	{
		printf("Right");
	}
	else
	{	
		if (k==10) k='X';
		else k+=48;
		printf("%d-%d%d%d-%d%d%d%d%d-%c",a,b,c,d,e,f,g,h,i,k);
	}
	return 0;
}
