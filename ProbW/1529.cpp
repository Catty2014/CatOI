//SDOJ #1529 �жϷ���
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
