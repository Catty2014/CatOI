/* Test181230-T4 Starwar
 * Union Set
 * True_STD
 */

#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int,int>pii;
#define ll long long
#define in read()
#define pb push_back
inline int read(){
    int x=0,f=1;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';return x*f;
}
const int mod=1e9+7;
const int maxn = 1e6+10;
const int maxm = 2e6+10;
vector<int>g[maxn];
int n,m,k,fa[maxn],f[maxn],q[maxn],ans[maxn];
int find(int x){
    return (x==fa[x])?x:fa[x]=find(fa[x]);
}void merge(int x,int y){
    int fx=find(x),fy=find(y);if(fx==fy)return;
    fa[fy]=fx;
}
signed main(){
    n=in;m=in;
        for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=in,y=in;x++,y++;
        g[x].push_back(y);g[y].push_back(x);
    }
    k=in;
    for(int i=1;i<=k;i++){
        q[i]=in;q[i]++;f[q[i]]=1;
    }
    for(int i=1;i<=n;i++)//统计最后的连通块 
        if(!f[i]){
            for(int j=0;j<g[i].size();j++)
                if(f[g[i][j]]==0)merge(i,g[i][j]); 
        }
    int cnt=0;
    for(int i=1;i<=n;i++)if(!f[i]&&fa[i]==i)cnt++; //最后的连通块 
    for(int i=k;i>=1;i--){
        ans[i]=cnt;
        f[q[i]]=0;cnt++;int fy=q[i];//将每个点依次加入集合 
        for(int j=0;j<g[q[i]].size();j++){
            int v=g[q[i]][j];
            if(f[v]==1)continue;
            int fx=find(v);
            if(fy==fx)continue;
            fa[fx]=fy;cnt--;

        }       
    }
    printf("%d\n",cnt);
    for(int i=1;i<=k;i++)printf("%d\n",ans[i]);
    return 0;
}