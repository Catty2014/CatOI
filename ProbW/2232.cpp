//什么时候，我能把这个列表填满呢(W1000~W4000)..

//上标程！

/*首先把询问转化为x到根的点权和。 
 *然后，假设修改的是x，对应的子树范围[L,R],那么D[L]+W,D[R+1]-W(<--???)
 *则x到1的点权和就是D[1]..D[L]的和，树状数组维护
 */

//线段树ver

//[s]震惊！某蒟蒻开始写线段树了！[/s]

#include<cstdio>
#include<algorithm>

using std::swap;

const int maxn=100010;
int n,m,x,y,u,v,op,cnt=0,sz=0;
int Head[maxn],Next[maxn<<1],V[maxn<<1];
int dep[maxn],L[maxn],R[maxn],f[maxn][20],w[maxn];
int lazy[maxn<<2];
 
void push_down(int root){
	if(lazy[root]){
		lazy[root<<1]+=lazy[root];
		lazy[root<<1|1]+=lazy[root];
		lazy[root]=0;
	}
}
 
void Update(int L,int R,int C,int l,int r,int root){
	if(L<=l&&R>=r){
		lazy[root]+=C;
		return;
	}
	int mid=(l+r)>>1;
	push_down(root);
	if(L<=mid) Update(L,R,C,l,mid,root<<1);
	if(R>mid)  Update(L,R,C,mid+1,r,root<<1|1);
}
 
int Query(int pos,int l,int r,int root){
	if(pos==0) return 0;
	if(l==r) return lazy[root];
	int mid=(l+r)>>1;
	push_down(root);
	if(pos<=mid) return Query(pos,l,mid,root<<1);
	else return Query(pos,mid+1,r,root<<1|1);
}
 
void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
}
 
void Add(int u,int v){
	++cnt;
	Next[cnt]=Head[u];
	V[cnt]=v;
	Head[u]=cnt;
}
 
void dfs(int u,int fa){
	L[u]=++sz;
	f[u][0]=fa; for(int i=1;i<19;++i) f[u][i]=f[f[u][i-1]][i-1];
	dep[u]=dep[fa]+1;
	for(int i=Head[u];i;i=Next[i]) if(V[i]!=fa) dfs(V[i],u);
	R[u]=sz;
}
 
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
 
int main(){
	read(n);
	for(int i=1;i<=n;++i)
		read(w[i]);
	for(int i=1;i<n;++i){
		read(u),read(v);
		Add(u,v),Add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i) Update(L[i],R[i],w[i],1,n,1);
	read(m);
	for(int i=1;i<=m;++i){
		read(op);
		if(op==1){
			read(x),read(v);
			Update(L[x],R[x],v,1,n,1);
		}
		if(op==2){
			read(x),read(y);
			int g=lca(x,y);
			int ansX=Query(L[x],1,n,1);
			int ansY=Query(L[y],1,n,1);
			int ansG=Query(L[g],1,n,1);
			int ansF=Query(L[f[g][0]],1,n,1);
			printf("%d\n",ansX+ansY-ansG-ansF);
		}
	}
}