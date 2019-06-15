//SDOJ #1602 ”„Ã¡µˆ”„
//Language:C++
//Difficulty:Lv.3
//Method:GREEDY,TREE,STACK

#include <bits/stdc++.h>
using namespace std;
#define forx1 for(int i=1;i<=n;i++)
#define forx2 for(int i=1;i<n;i++)
#define sf(x) scanf("%d",&x)

struct Node
{
	int fish,lake;
	Node(int _fish=0,int _lake=0):fish(_fish),lake(_lake) {};
	bool operator < (const Node&t) const
	{
		return  fish<t.fish;
	}
};
int n,f[133],d[133],t[133];
int ans,m,t1=0,_time,_max=0;

int main(){
	scanf("%d",&n);
	forx1 sf(f[i]);
	//printf("1111111");
	forx1 sf(d[i]);
	//printf("2222222");
	forx2 sf(t[i]);
	//printf("3333333");
	sf(m);
	for(int k=1;k<=n;k++)
	{
		_time=m-t1;
		ans=0;
		priority_queue<Node> heap;
		for(int i=1;i<=k;i++)
			heap.push(Node(f[i],i));
		while(_time>0&&heap.top().fish>0)
		{
			Node a=heap.top();
			heap.pop();
			ans+=a.fish;
			a.fish-=d[a.lake];
			heap.push(a);
			_time--;
		}
		if(ans>_max) _max=ans;
		t1+=t[k];
	}
	printf("%d",_max);
	return 0;
}


