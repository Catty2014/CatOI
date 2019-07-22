//STD
#include<bits/stdc++.h>
using namespace std;
#define mset(name,val) memset(name,val,sizeof name)
const int N=150200,M=300200,K=200200,MaxlogN=25;
struct Link{int x,y,val;}l[M];
struct edge{int ver,next;}e[2*N];
int n,m,q,t,fa[2*N],val[2*N],depth[2*N],f[2*N][MaxlogN],Last[2*N];
inline void input(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&l[i].x,&l[i].y,&l[i].val);
}
inline bool compare(Link a,Link b)
{
    return a.val<b.val;
}
inline void insert(int x,int y)
{
    e[++t].ver=y;e[t].next=Last[x];Last[x]=t;
}
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void Exkruscal(void)
{
    sort(l+1,l+m+1,compare);
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=find(l[i].x),y=find(l[i].y);
        if(x==y)continue;
        fa[x]=fa[y]=++n;
        val[n]=l[i].val;
        insert(n,x);
        insert(n,y);
    } 
}
inline void dfs(int x,int dep)
{
    depth[x]=dep;
    for(int i=Last[x];i;i=e[i].next)
    {
        int y=e[i].ver;
        if(f[x][0]==y)continue;
        f[y][0]=x;
        dfs(y,dep+1); 
    }
}
inline void dp(void)
{
    f[n][0]=-1;
    for(int k=1;(1<<k)<n;k++)
        for(int i=1;i<=n;i++)
            if(f[i][k-1]<0)f[i][k]=-1;
            else f[i][k]=f[f[i][k-1]][k-1];
}
inline int LCA(int x,int y)
{
    if(depth[x]>depth[y])
        swap(x,y);
    for(int d=depth[y]-depth[x],i=0;d;d>>=1,i++)
        if(1&d)y=f[y][i];
    if(x==y)return x;
    for(int i=MaxlogN-1;i>=0;i--)
    {
        if(f[x][i]^f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
inline void solve(void)
{
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",val[LCA(a,b)]);
    }
}
int main()
{
    #ifdef FILE_OUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    #endif
    input();
    Exkruscal();
    dfs(n,1); 
    dp();
    solve();
    return 0;
}