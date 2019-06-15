//SDOJ #1601 合并果子
//Language:C++
//Difficulty:C++
//Method:Tree

#include <bits/stdc++.h>
using namespace std;

int stk[100086],size=0;                       //STacK
int n,x;
int ans=0;
void push(int x)
{
	int cur;
	stk[++size]=x;
	cur=size;                                 //CURrent
	while(cur>1&&stk[cur]<stk[cur>>1])
	{
		swap(stk[cur],stk[cur>>1]);           //swap:Included Function
		cur=cur>>1;
	}
}

void pop()
{
	stk[1]=stk[size--];
	int cur=1;
	while(cur*2<=size)
	{
		int son=cur*2;
		if(son+1<=size&&stk[son+1]<stk[son]) son++;
		if(stk[cur]<stk[son]) break;
		swap(stk[son],stk[cur]);
		cur=son;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		push(x);
	}
	for(int i=1;i<=n-1;i++)
	{
		x=stk[1];
		pop();
		int y=stk[1];
		pop();
		ans+=x+y;
		push(x+y);
		//printf("%d\n",ans);
	}
	printf("%d",ans);
	return 0;
}
