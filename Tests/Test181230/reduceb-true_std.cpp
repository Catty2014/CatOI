/* Test181230-T2 Reduce2
 * DFS????!!!!
 * True_STD
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in read() 
inline int read(){
    int x=0,f=1;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';return x*f;
}
const int mod=1e9+7;
const int maxn = 1e5+10;
struct node{
    int x,y,id;
}a[maxn],b[maxn],c[maxn];
int n; int f[maxn]={};int k=0,ans=0x7fffffff;
int cmp1(node m,node n){
    return m.x<n.x;
}
int cmp2(node m,node n){
    return m.y<n.y;
}
void solve(){
    int tmp=0,p=0;
    for(int i=1;i<=k;i++)if(!f[i])a[++p]=c[i];  
    sort(a+1,a+p+1,cmp1);
    tmp=a[p].x-a[1].x;
    sort(a+1,a+p+1,cmp2);
    tmp*=a[p].y-a[1].y;
    ans=min(ans,tmp);
    }
void dfs(int p,int s){
    if(s==3){
        solve();
        return ;
    }
    if(p==k+1)return ;
    f[p]=1;
    dfs(p+1,s+1);
    f[p]=0;
    dfs(p+1,s);
}
signed main(){
    n=in;
    for(int i=1;i<=n;i++){
        a[i].x=in;a[i].y=in;a[i].id=i;
        b[i]=a[i];
    }
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+n+1,cmp2);
    
    for(int i=1;i<=4;i++){//最四层取出枚举
        if(!f[a[i].id])c[++k]=a[i];
        f[a[i].id]=1; 
        if(!f[b[i].id])c[++k]=b[i];
        f[b[i].id]=1; 
    }
    for(int i=n-3;i<=n;i++){
        if(!f[a[i].id])c[++k]=a[i];
        f[a[i].id]=1; 
        if(!f[b[i].id])c[++k]=b[i];
        f[b[i].id]=1; 
    }   
    memset(f,0,sizeof(f));
    dfs(1,0);
    cout<<ans;
    return 0;
}