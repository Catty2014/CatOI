#include<bits/stdc++.h>
#define fp(i,a,b) for( int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for( int i=a,I=b-1;i>I;--i)
#define go(u) for( int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sd(T&x){
    char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45)y=-1;x=c-48;
    while(c=gc(),47<c&&c<58)x=x*10+c-48;x*=y;
}
char sr[1<<21],z[20];int C=-1,Z;
inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
template<class T>inline void we(T x){
    if(C>1<<20)Ot();if(x<0)sr[++C]=45,x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++C]=z[Z],--Z){};sr[++C]='\n';
}
const int N=1e5+5;
typedef int arr[N];
typedef long long ll;
struct eg{int nx,to;}e[N<<1];
int n,df[N*5],*f[N],*idf=df+1;arr fi,fa,mx,son;ll ans,dg[N*5],*g[N],*idg=dg+1;
inline void add(int u,int v){static int ce=0;e[++ce]={fi[u],v},fi[u]=ce;}
void dfs(int u){
    go(u)if(v^fa[u]){
        fa[v]=u,dfs(v),cmax(mx[u],mx[v]);
        if(mx[v]>mx[son[u]])son[u]=v;
    }++mx[u];
}
inline void Give(int u){f[u]=idf,idf+=mx[u]+1,idg+=mx[u]+1,g[u]=idg,idg+=mx[u]+1;}
void dp(int u){
    if(son[u])f[son[u]]=f[u]+1,g[son[u]]=g[u]-1,dp(son[u]);
    f[u][0]=1,ans+=g[u][0];
    go(u)if(v^fa[u]&&v^son[u]){
        Give(v),dp(v);
        fd(j,mx[v],0)ans+=g[v][j]*f[u][j-1]+g[u][j+1]*f[v][j];  
        fp(j,0,mx[v])g[u][j]+=g[v][j+1]+.3,f[u][j]+=f[v][j-1];
    }
}
int main(){
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.ans","w",stdout);
#endif
    sd(n);int u,v;
    fp(i,2,n)sd(u),sd(v),add(u,v),add(v,u);
    dfs(1);Give(1);dp(1);
    printf("%lld\n",ans);
return 0;
}
