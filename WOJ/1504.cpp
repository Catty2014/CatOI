//SDOJ #1504 ²éÕÒ¶þ²æÊ÷
//Language:C++
//Difficulty:Lv.2
//Method:Tree

#include <bits/stdc++.h>
using namespace std;

struct Tree
{
	int data,L,R;
}Tr[133];
int n,m,t;
void Dfs(int x)
{
	if(x==0) return 0;
	Dfs(Tr[x].l);
	t++;
	if(Tr[x].data==m) cout<<t;
	Dfs(Tr[x].r);
}
int main()
{
	cin>>n>>m;
	memset(Tr,0,sizeof(T));
	for(int i=1;i<=n;i++)
	{
		cin>>Tr[i].data>>Tr[i].L
	}
	return 0;
}
