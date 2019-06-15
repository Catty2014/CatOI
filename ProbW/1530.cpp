//SDOJ #1530 ÅÐ¶ÏÊý×Ö
//C

#include <stdio.h>

int main()
{
	char c;
	scanf("%c",&c);
	if (c<48||c>57)
	{
	printf("%c",c);
	}
	else
	{
	printf("%d",(c-48)*(c-48));
    }
	return 0;
}
