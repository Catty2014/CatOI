#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int v1,v2,t,s,l,tt,tr,st=0,sr=0,_s=0;
	scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&l);
	tt=l/v2;
	tr=l/v1;;
	while(sr<l&&st<l)
	{
		printf("T:%d   R:%d\n",st,sr);
		st+=v2;
		sr+=v1;
		if(sr<l&&st<l)
		{
			_s=sr-st;
			if(_s>=t)
			{
				_s-=v2*s;
				if(_s<0)
				{
					if(st>=l)
					{
						cout<<"T\n"<<tt;
						return 0;
					}
				}
				tr+=s;
			}
		}
		else break;
	}
	if(tr==tt)
	{
		cout<<"D\n"<<tt;
		return 0;
	}
	if(tr>tt) cout<<"T\n"<<tt;
	else cout<<"R\n"<<tr;
	return 0;
}
