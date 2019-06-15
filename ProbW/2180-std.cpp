#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int n;
ll c[55];
ll pow(ll b,int p){
	ll ans=1;
	b%=mod;
	while(p){
		if(p&1)ans=ans*b%mod;
		p>>=1;
		b=b*b%mod;
	}
	return ans;
}//快速幂 
ll inv(ll x){
	return pow(x,mod-2);
}//求逆元 
int main(){
	scanf("%d",&n);
	n-=2;
	c[0]=1;
	c[1]=1;
	c[2]=2;
	for(int i=3;i<=n;i++)
		c[i]=c[i-1]*(4*i-2)%mod*inv(i+1)%mod;//f(n)=f(n-1)*(4n-2)/(n+1)    
		//因为除一个数效率低下，乘这个数的逆元=除以这个数 
	printf("%lld",c[n]);
	return 0;
}
