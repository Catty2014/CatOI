#include<bits/stdc++.h>
using namespace std;
#define N 11
int n,k,a[N],cnt=0,flag=0;
struct Node{
	char w;
	int id;
}b[N];
struct Node1{
	char x,y;
	int xx,yy,xxx,yyy;
}c[N];
int cmp(Node x,Node y){
	return x.id<y.id;
}
int main(){
    // freopen("place.in","r",stdin);
    // freopen("place_std.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b[i].w;
		b[i].id=b[i].w-'a'+1;
		a[i]=i;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<k;i++){
		cin>>c[i].x>>c[i].y;
		c[i].xxx=0;
		c[i].yyy=0;
		for(int j=0;j<n;j++){
			if(c[i].x==b[j].w){
				c[i].xx=j;
			}
			if(c[i].y==b[j].w){
				c[i].yy=j;
			}
		}
	}
	do{
		flag=0;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				if(a[j]==c[i].xx){
					c[i].xxx++;
				}
				if(a[j]==c[i].yy){
					if(c[i].xxx==0){
						flag=1;
					}
				}
			}
			c[i].xxx=0;
			c[i].yyy=0;
		}
		if(flag==1){
			continue;
		}
		for(int i=0;i<n;i++){
			cout<<b[a[i]].w;
		}
		cout<<endl;
	}
	while(next_permutation(a,a+n));
	return 0;
}
