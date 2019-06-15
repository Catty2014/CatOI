/******************************
 * W1468 百事世界杯
 * Expectation DP    
 ******************************/

#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,p;
long long gcd(long long x,long long y)
{
    if(x<y)
    {
        y-=x;
        return gcd(x,y);
    }
    if(x>y)
    {
        x-=y;
        return gcd(x,y);
    }
    return x;
}
int dig(long long n)
{
    int ans=0;
    while(n!=0)
    {
        n/=10;
        ans++;
    }
    return ans;
}
void pf(int n,int id)
{
    for(int i=1;i<=n;i++)
    {
        printf("%c",id);
    }
    return ;
}
int main(){
	int n,i;cin>>n;a=1;b=1;
	for(i=2;i<=n;i++){
	    a=a*i+1*b;b*=i;
        p=a;a/=gcd(a,b);b/=gcd(p,b); 
	}
	a*=n;
    int _g=gcd(a,b);
    a/=_g;
    b/=_g;
	if(a%b==0) printf("%lld\n",a/b);
	else {
        long long s=(long long)(a/b);
        a=a%b;
        int ds=dig(s);
        int db=dig(b);
        pf(ds+1,32);
        printf("%lld\n",a);
        printf("%lld ",s);
        pf(db,45);
        printf("\n");
        pf(ds+1,32);
        printf("%lld\n",b);
	}
	return 0;
} 