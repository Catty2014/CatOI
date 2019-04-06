//SDOJ #1011 ��������
//C

#include <cstdio>

int a[10001]={0};

 
void Read(int & p)
{
	p=0;
	char c=getchar();
	while(c<'0' or c>'9') c=getchar();
	while(c>='0' and c<='9')
		p=p*10+(c-'0'),c=getchar();
}
 
inline void write(int x){
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}


int main()
{
	int n=0,x=0;
	Read(n);
	for(int i=1;i<=n;i++)
	{
		Read(x);
		a[x]++;
	}
	for(int i=1;i<=10000;i++)
	{
        for(;a[i];a[i]--)
        {
        	write(i);
        	printf(" ");
		}
	}
	return 0;
}
