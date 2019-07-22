//SDOJ #1211 ��������
//C++

#include <stdio.h>

int main()
{
	
	/*��ʼ�����*/ 
	
	int v1,v2,s,t,l;
	scanf("%d%d%d%d%d",&v1,&v2,&s,&t,&l);
	int tt,tr;
	
	/*���㲿��*/
	
	tt = l/v2;
	
	int sr,st,trt,trr=0,n,_s;
	
	do{
		trr++;
		st = trr*v2;
		sr = trr*v1;
		if (sr!=l)
		{
		_s = sr-st;
		for(n=0;_s>=s;_s=_s-v2*t)
		{
			n++;
		}
		}
		tr = trr+n*t;
	}while(sr!=l);
	
	
	/*�Ƚϲ���*/ 
	
	if (tt>tr)
	{
		printf("R\n%d",tr);
		return 0;
	}
	
	if (tt<tr)
	{
		printf("T\n%d",tt);
		return 0;
	}
	
	if (tt==tr)
	{
		printf("D\n%d",tt);
		return 0;
	}
} 