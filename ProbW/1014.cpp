//

#include<bits/stdc++.h>

using namespace std;

int n,a[11];
bool b[11];

void Prnt()
{
	for(int i=1; i<=n; i++)
		printf("%5d",a[i]);
	printf("\n");
}

int srt(int dig)
{
	for(int i=1; i<=n; i++)
		if(b[i]==0)
		{
			a[dig]=i;
			b[i]=1;
			if(dig==n)
				Prnt();
			else
				srt(dig+1);
			b[i]=0;
		}
}

int main()
{
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	srt(1);
	return 0;
}
