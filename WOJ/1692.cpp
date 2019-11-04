#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef  long long ll;
typedef long double ldb;
const ldb inf=9223372036854775808.0;
int num,t,k,i,pr[16]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll ans[2000];
struct edge{
    ll x,y;
} h[45000],a[5000];
ll read(){
    ll sum=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9'){
        sum=sum*10+c-'0';
        c=getchar();}
    return sum;
}
bool cmp(edge a,edge b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
inline void dg(int x,ll y,ldb z,int u,int p){
    h[++num].y=y,h[num].x=(ll)z;
    ll k=1; int i;
    if (x>15) return;
    fo(i,1,p){
        k*=pr[x],z=z*(i+u)/i;
        if (y>inf/k||z>inf) break; 
        dg(x+1,y*k,z,u+i,i);}
}
int main(){
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    dg(1,1,1,0,63);
    sort(h+1,h+num+1,cmp);
    t=read();
    fo(i,1,t) a[i].x=read(),a[i].y=i;
    sort(a+1,a+t+1,cmp);
    k=2;
    fo(i,1,t){
        while (k<=num&&a[i].x>h[k].x) k++;
        ans[a[i].y]=h[k].y;
    }
    fo(i,1,t) printf("%lld\n",ans[i]);
}
