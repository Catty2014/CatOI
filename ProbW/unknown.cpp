#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
int last [M*2],f[N][33],q[N],st[N],Log[N];
int n,m,l,r,x;
inline int read(){
    int data=0;int w=1; char ch=0;
    ch=getchar();
    while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch>='0' && ch<='9') data=(data<<3)+(data<<1)+ch-'0',ch=getchar();
    return data*w;
}
void inti(){
	for(int i=1;i<=n;i++)f[i][0]=q[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i-1)<=n;j++)
			f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}
int Q(int l,int r){
	int k=Log[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int check(int l,int r){
	if(st[l]==r)return l;
	if(st[r]<l)return r+1;
	int le=l,ri=r;
	while(le<ri){
		int mid=(le+ri)>>1;
		if(st[mid]<l)le=mid+1;
		else ri=mid;
	}
	return le;
}
int main(){
	n=read();m=read();
	Log[0]=1;
	for(int i=2;i<=n+10;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++){
		x=read();
		st[i]=max(st[i-1],last[x+M]+1);
		q[i]=i-st[i]+1;
		last[x+M]=i;
	}
	inti();
	while(m--){
		l=read();
		r=read();
		l++;r++;
		int mid=check(l,r),ans=0;
		if(mid>l)ans=mid-l;
		if(mid<=r){
			ans=max(ans,Q(mid,r));
		}
		printf("%d\n",ans);
	}
	return 0;
}
