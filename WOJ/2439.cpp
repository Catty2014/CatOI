#include<bits/stdc++.h>

typedef long long ll;

const int N=50004;
const int mod=1000000007;

int uni,n;

inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(int a,int b){return a>=b?a-b:a-b+mod;}
struct node{
	int len,cnt;
	void operator+=(const node &b){
		if(len>b.len)return;
		if(len<b.len)*this=b;
		else cnt=add(cnt,b.cnt);
	}
}t[N],f[N];

#define lowbit(x) (x&(-x))
inline void update(int pos,const node &a){
	for(;pos<=uni;pos+=lowbit(pos))t[pos]+=a;
}

inline node query(int pos){
	node res=(node){0,1};
	for(;pos;pos-=lowbit(pos))res+=t[pos];
	return res;
}

int a[N],b[N];
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        a[i]=b[i]=tmp;
    }
	std::sort(b+1,b+n+1);
	uni=std::unique(b+1,b+n+1)-b-1;
	for(int  i=1;i<=n;++i)a[i]=std::lower_bound(b+1,b+uni+1,a[i])-b;
	for(int  i=1;i<=n;++i){
		f[i]=query(a[i]-1);++f[i].len;
		update(a[i],f[i]);
	}
	node ans=(node){0,0};
	for(int  i=1;i<=n;++i)ans+=f[i];
    printf("%d\n",ans.cnt);
	return 0;
}
