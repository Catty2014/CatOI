//SDOJ #1529 ÅÐ¶Ï·ûºÅ
//C

#include <stdio.h>

int main()
{
	char c;
	scanf("%c",&c);
	if (!(c<97||c>122))
	{
	c = c+1;
	}
	printf("%c",c);
	return 0;
}
