//SDOJ #1604 –Ú¡–∫œ≤¢
//Language:C++
//Difficulty:Lv.3
//Method:Heap

#include <bits/stdc++.h>
using namespace std;

int a[133333],b[133333],n;

struct Node
{
	int id,s;
	Node(int _id=0,int _s=0):id(_id),s(_s)
	{
	};
	bool operator<(const Node&t) const
	{
		return s<t.s;
	};
} x;

struct Heap
{
	int size;
	Node h[100086];
	Node top()
	{
		return h[1];
	}
	void push(Node x)
	{
		int cur;                                 //CURrent
		h[++size]=x;
		cur=size;
		while(cur>1&&h[cur]<h[cur>>1])
		{
			swap(h[cur],h[cur>>1]);
			cur=cur>>1;
		}
	}
	void pop()
	{
		h[1]=h[size--];
		int cur=1;
		while(cur*2<=size)
		{
			int son=cur*2;
			if(son+1<=size&&h[son+1]<h[son]) son++;
			if(h[cur]<h[son]) break;
			swap(h[son],h[cur]);
			cur=son;
		}
	}
} h;

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)scanf("%d",&b[i]);
	for(int i=1; i<=n; i++)h.push((Node)
	{
		1,a[1]+b[i]
	});
	for(int i=1; i<=n; i++)
	{
		x=h.top();h.pop();
		printf("%d ",x.s);
		x.s=x.s-a[x.id]+a[x.id+1];
		x.id++;
		h.push(x);
	}
		return 0;
}

