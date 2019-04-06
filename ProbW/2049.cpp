//SDOJ #2049 Ñî»ÔÈý½Ç
//Language:C++

#include <cstdio>

int a[22][22]= {0};

int main()
{
	int l;
	scanf("%d",&l);

	for(int i=1; i<=l; i++)
	{
		for(int j=1; j<=i; j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
			a[1][1]=1;
			a[2][1]=1;
			a[2][2]=1;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
