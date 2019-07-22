//SDOJ #1298 QQÃÜÂë
//Language:C

#include <cstdio>

int main()
{
	int digit;
	for(;;)
	{
		scanf("%c",&digit);
		//printf("%c %d",digit,digit);
		if(digit>=65&&digit<=90)
		{
			digit+=32;
			printf("%c",digit);
			continue;
		}
		if(digit>=97&&digit<=122)
		{
			digit-=32;
			printf("%c",digit);
			continue;
		}
		if(digit=='.')
		{
			break;
		}
	}
	return 0;
}
