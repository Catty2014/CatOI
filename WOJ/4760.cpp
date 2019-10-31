#include<bits/stdc++.h>
#define dl double 
#define N 3000005
using namespace std;
dl read()
{
    dl x=0,y=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')y=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*y;
}
struct node{
	double a,b,s;
}f[N];
double ans;
int tot=0;
bool comp(node a,node b){return a.s<b.s;}
int main(){
	/* freopen("spongebob.in","r",stdin); */
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
	int n=read();	
	f[0].a=0;f[0].b=0;
	if(n==1){
		double a1=read(),b1=read();
		if(a1==0) printf("%lf",b1);
		else printf("0");
		return 0;
	}
	for(int i=1;i<=n;++i){
		double a1=read();double b1=read();
		if(a1==0) ans+=b1;
		else{
			++tot;
			f[tot].a=a1;f[tot].b=b1;
			f[tot].s=-b1/a1;
		}
	}
	sort(f+1,f+1+tot,comp);
	long long aa=0,bb=0;
	for(int i=1;i<=tot;++i){
		aa+=f[i].a;
		bb+=f[i].b;
	}
//	printf("%lld %lld\n",aa,bb);
	double ans=9889898989898;
	for(int i=1;i<=tot;++i){
		aa=aa-f[i].a*2;
		bb=bb-f[i].b*2;
		
		double an=abs(f[i].s*aa+bb);
		printf("i=%d aa=%lld bb=%lld f[i].s=%lf an=%lf\n",i,aa,bb,f[i].s,an);
		ans=min(ans,an);
	}
//	aa=aa-f[tot].a*2;
//	bb=bb-f[tot].b*2;
//	double an=f[tot].s*aa+bb;
//	ans=min(ans,an);
	printf("%lf",ans);
	return 0;
}
