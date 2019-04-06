//SDOJ #1510 ¶þ²æÊ÷µÄ±éÀú
//Lang:C++
//Diff:Lv.2
//Meth:STD

#include <bits/stdc++.h>
#define pfe printf("\n")
using namespace std;

int t,n,root,up[1233],d1[1233],d2[1233];

void dfs(int p,int d)
{
	if(d==1) printf("%d ",p);
	if(d1[p]) dfs(d1[p],d);
	if(d==2) printf("%d ",p);
	if(d2[p]) dfs(d2[p],d);
	if(d==3) printf("%d ",p);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&t);
		scanf("%d %d",&d1[t],&d2[t]);
		up[d1[t]]=1;
		up[d2[t]]=1;
		//printf("%d %d %d\n")
	}
	for(int i=1; i<=n; i++)
	{
		if(up[i]==0)
		{
			root=i;
			break;
		}
	}
	dfs(root,1);
	pfe;
	dfs(root,2);
	pfe;
	dfs(root,3);
	return 0;
}

