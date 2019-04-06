#include<bits/stdc++.h>
using namespace std;
#define lc (q<<1)
#define rc (q<<1|1)
const int N=100010;
int a[N],n,m;
struct Node{
	long long l,r,lazy,amount1;
	long long endurance1,le1,re1,endurance0,le0,re0;
}tree[4*N];

inline int read(){
	int ans=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*w;
}

inline void pushnow(int q,int la){
//	printf("a1a");
	if(la==3){//取反
		swap(tree[q].le0,tree[q].le1);
		swap(tree[q].re0,tree[q].re1);
		swap(tree[q].endurance0,tree[q].endurance1);
		tree[q].amount1=tree[q].r-tree[q].l+1-tree[q].amount1;
		tree[q].lazy=la;
	}
	else if(la==2){//变1 
		tree[q].endurance1=tree[q].r-tree[q].l+1;
		tree[q].amount1=tree[q].le1=tree[q].re1=tree[q].endurance1;
		tree[q].endurance0=tree[q].le0=tree[q].re0=0;
		tree[q].lazy=la;
	}
	else if(la==1){//变0 
		tree[q].endurance0=tree[q].r-tree[q].l+1;
		tree[q].le0=tree[q].re0=tree[q].endurance0;
		tree[q].amount1=tree[q].endurance1=tree[q].le1=tree[q].re1=0;
		tree[q].lazy=la;
	}
}

inline void pushdown(int q){
//	printf("a2a");
	if(tree[q].lazy){
//		printf("a3a");
		pushnow(lc,tree[q].lazy);
		pushnow(rc,tree[q].lazy);
		tree[q].lazy=0;
	}
}

inline Node operator + (const Node &a,const Node &b){
	Node res;
//	printf("a4a");
	res.le1=a.le1;	
	if(a.endurance1==a.r-a.l+1)
		res.le1=max(res.le1,a.endurance1+b.le1);
		
	res.re1=b.re1;
	if(b.endurance1==b.r-b.l+1)
		res.re1=max(res.re1,b.endurance1+a.re1);
		
	res.endurance1=max(max(a.endurance1,b.endurance1),a.re1+b.le1);
	
	res.le0=a.le0;
	if(a.endurance0==a.r-a.l+1)
		res.le0=max(res.le0,a.endurance0+b.le0);
		
	res.re0=b.re0;
	if(b.endurance0==b.r-b.l+1)
		res.re0=max(res.re0,b.endurance0+a.re0);
		
	res.endurance0=max(max(a.endurance0,b.endurance0),a.re0+b.le0);
	
	res.amount1=a.amount1+b.amount1;
	
	return res;
}
void build(int q,int l,int r){
 //	printf("a5a");
	tree[q].l=l;
	tree[q].r=r;
	if(l==r){
		if(a[l]){
			tree[q].endurance1++;
			tree[q].le1++;
			tree[q].re1++;
			tree[q].amount1++;
		}
		else{
			tree[q].endurance0++;
			tree[q].le0++;
			tree[q].re0++;
		}
		return;
	}
	int mid=(l+r)/2;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[q]=tree[lc]+tree[rc];
	return;
}
inline void update(int q,int ql,int qr,int la){
//	printf("a6a");
	if(ql<=tree[q].l&&tree[q].r<=qr){
		pushnow(q,la);
		return;
	}
	int mid=(tree[q].l+tree[q].r)/2;
	pushdown(q);
	if(ql<=mid)
		update(lc,ql,qr,la);
	else
		update(rc,ql,qr,la);
	tree[q]=tree[lc]+tree[rc];
	return;
}
inline Node query(int q,int ql,int qr){
//	printf("a7a");
	if(ql<=tree[q].l&&tree[q].r<=qr)
		return tree[q];
	pushdown(q);
	int mid=(tree[q].l+tree[q].r)/2;
	if(qr<=mid)
		return query(lc,ql,qr);
	if(ql>mid)
		return query(rc,ql,qr);
	return query(lc,ql,mid)+query(rc,mid+1,qr);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	printf("100");
	build(1,1,n);
//	printf("end");
	for(int i=1;i<=m;i++){
//		printf("a8a");
		int a,b,c;
		cin>>a>>b>>c;
		b++;
		c++;
		if(a==0){//全变0
//			printf("a9a");
			update(1,b,c,1);
			continue;
		}
		if(a==1){//全变1 
			update(1,b,c,2);
			continue;
		}
		if(a==2){//取反 
			update(1,b,c,3);
			continue;
		}
		if(a==3){//统计1 
			printf("%d\n",query(1,b,c).amount1);
		}
		if(a==4){//统计连续1 
			printf("%d\n",query(1,b,c).endurance1);
		}
	}
	return 0; 
}