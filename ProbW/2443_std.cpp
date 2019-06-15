#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m,c,k;
const int N=100001;
int a[N],tmp[N],idx[N];
struct node{
	int l,r,ans,id;
	/*bool operator < (const node&t){
		return (l<idx[t.l])||(r<t.r&&idx[t.l]==idx[l]);
	}*/
}q[N];
inline bool order(node c,node b){
	if(idx[c.l]==idx[b.l]) return c.r<b.r;
	return c.l<b.l;
}
inline bool cmp(const node &c,const node &b){
	return c.id<b.id;
}
#define ha cout<<"check\n";
inline void solve(){
	int l=0,r=0,ans=0;
	for(int i=1;i<=m;i++){
		while(r<q[i].r){
			r++;
			tmp[a[r]]++;
			if(tmp[a[r]]%2==0)               ans++;
			if(tmp[a[r]]%2==1&&tmp[a[r]]!=1) ans--;
		}
        printf("ans==%d\n",ans);
		while(l>q[i].l){
			l--;
			tmp[a[l]]++;
			if(tmp[a[l]]%2==0) 			     ans++;
			if(tmp[a[l]]%2==1&&tmp[a[l]]!=1) ans--;
		}
        printf("ans==%d\n",ans);
		while(r>q[i].r){
			tmp[a[r]]--;
			if(tmp[a[r]]%2==0&&tmp[a[r]]!=0) ans++;
			if(tmp[a[r]]%2==1)                  ans--;
			r--;
		}
        printf("ans==%d\n",ans);
		while(l<q[i].l){
			tmp[a[l]]--;
			if(tmp[a[l]]%2==0&&tmp[a[l]]!=0) ans++;
			if(tmp[a[l]]%2==1)                  ans--;
			l++;
		}
		q[i].ans=ans;
        printf("ans==%d\n",ans);
	}
}
int main(){
	n=read(),c=read(),m=read();
	k=sqrt(n);
	for(int i=1;i<=n;i++){
		a[i]=read();
		idx[i]=(i-1)/k+1;
	}
	for(int i=1;i<=m;i++)
		q[i]=(node){read(),read(),0,i};
	sort(q+1,q+m+1,order);
	solve();
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++) write(q[i].ans),putchar('\n');
	return 0;
}