#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[100][20],gb,xb;
	int n,g=0,q=0,max=0,qm,bj,psg,k;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%s %d %d %c %c %d",&s[i],&qm,&bj,&gb,&xb,&psg);
		int g=0;
		if((qm>80)&&(psg>0)) g+=8000;
		if((qm>85)&&(bj>80)) g+=4000;
		if(qm>90) g+=2000;
		if((xb=='Y')&&(qm>85)) g+=1000;
		if((gb=='Y')&&(bj>80)) g+=850;
		q+=g;
		if(g>max)
		{
			max=g;
			k=i;
		}
	}
	printf("%s\n%d\n%d",s[k],max,q);
	return 0;
}
