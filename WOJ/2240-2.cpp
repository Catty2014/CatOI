#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define M 200010
int n,m,num,f[N],d[N],dt[N],vis[N];
struct node{
	int u,v,w,nxt;
}e[M];
void add(int u,int v,int w){
	e[++num].u=u;e[num].v=v;e[num].w=w;e[num].nxt=f[u];f[u]=num;
}
typedef pair<int,int> T;
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	memset(dt,0x3f,sizeof(dt));
	priority_queue< T,vector<T>, greater<T> >q;
	d[s]=0;dt[s]=0;q.push(make_pair(d[s],s));
	while(!q.empty()){
		pair<int,int> t=q.top();q.pop();
		int dd=t.first,u=t.second;
		if(vis[u]) continue;vis[u]=1;
		for(int i=f[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(d[v]>dd+w){dt[v]=min(d[v],dt[v]);d[v]=dd+w; q.push(make_pair(d[v],v));}
			if(d[v]<dd+w&&dt[v]>dd+w) {dt[v]=dd+w;q.push(make_pair(dt[v],v));};
			//q.push(make_pair(d[v],v));
		}
	}
}
int main(){
	int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=m;i++){cin>>x>>y>>z;add(x,y,z);add(y,x,z);}
	dijkstra(1);
	cout<<dt[n];
	return 0;
}
