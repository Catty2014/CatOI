//SDOJ #1502 求二叉树的后序遍历
//Language:C++
//Difficulty:Lv.2
//Method:Tree

#include <bits/stdc++.h>
using namespace std;

string sf,sm;

void solve(int L1,int R1,int L2,int R2)
{
	//printf("%d %d %d %d\n",L1,R1,L2,R2);
	int m=sm.find(sf[L1]);
	//printf("%d\n",m);
	if(m>L2) solve(L1+1,L1+m-L2,L2,m-1);
	if(m<R2) solve(L1+m-L2+1,R1,m+1,R2);
	cout<<sf[L1];
}

int main()
{
	cin>>sf>>sm;
	solve(0,sf.length()-1,0,sm.length()-1);
	cout<<endl;
	return 0;
}
