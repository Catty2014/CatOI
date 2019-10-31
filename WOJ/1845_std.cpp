#include<bits/stdc++.h>
using namespace std;
#define Inc(i,L,r) for(int i=(L);i<=(r);++i)
const int N = 1e5+10;
int n,m,w[N];
struct Edge{
	int cnt,h[N],to[N<<1],next[N<<1];
	inline void add(int x,int y){
		next[++cnt]=h[x];
		to[cnt]=y;
		h[x]=cnt;
	}
}e;
int sign,tj[N],ll[N];
int top,s[N],istk[N];
int scc,bl[N];
int mn[N],mx[N];
vector<int>vec[N];
void Tarjan(int u){
	tj[u]=ll[u]=++sign;
	s[++top]=u;
	istk[u]=1;
	int v;
	for(int p=e.h[u];p;p=e.next[p]){
		v=e.to[p];
		if(!tj[v]){
			Tarjan(v);
			ll[u]=min(ll[u],ll[v]);
		}
		else if(istk[v])ll[u]=min(ll[u],tj[v]);
	}
	if(ll[u]==tj[u]){
		scc++;
		mx[scc]=-(1<<30),mn[scc]=1<<30;
		do{
			v=s[top--];
			istk[v]=0;
			vec[bl[v]=scc].push_back(v);
			mx[scc]=max(mx[scc],w[v]);
			mn[scc]=min(mn[scc],w[v]);
		}while(v!=u);
	}
}
bool inq[N];
int f[N][2];
queue<int>Q;
inline void bfs(){
	Q.push(bl[1]);
	f[bl[1]][0]=mn[bl[1]];
	f[bl[1]][1]=mx[bl[1]]-mn[bl[1]];
	while(!Q.empty()){
		int nc=Q.front();Q.pop();
		inq[nc]=0;
		int size=vec[nc].size();
		Inc(i,0,size-1){
			int x=vec[nc][i];
			for(int p=e.h[x];p;p=e.next[p]){
				int to=e.to[p];
				if(bl[to]==nc||inq[bl[to]])continue;
				inq[bl[to]]=1;
				Q.push(bl[to]);
				f[bl[to]][0]=min(mn[bl[to]],f[nc][0]);
				f[bl[to]][1]=max(mx[bl[to]]-f[bl[to]][0],f[nc][1]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	Inc(i,1,n)scanf("%d",&w[i]);
	Inc(i,1,m){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		e.add(x,y);if(z==2)e.add(y,x);
	}
	Tarjan(1);
	bfs();
	cout<<f[bl[n]][1]<<"\n";
    printf("%d\n",f[bl[n]][1]);
	return 0;
}
