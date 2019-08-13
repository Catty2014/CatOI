/****************************************
 * W2978
 * LCT ...  or SMT?
 ****************************************/
#include <cstdio>
#include <algorithm>

const int N=100233;
const int M=N*20;
typedef long long ll;

int fa[N];
int edgeCnt,edgeTo[N],edgeNxt[N*2];
int f[N*2];
int size[M],nl[M],nr[M];
int root[N*20],n,b,vis[N],l[N],r[N];
int deep[N];
int x[N],y[N];
int k[N];
int smtCnt;

int ufsSearch(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=ufsSearch(fa[x]);
    }
    return fa[x];
}

void graphAdd(int x,int y)
{
    edgeNxt[++edgeCnt]=edgeTo[x];
    edgeTo[x]=edgeCnt;
    f[edgeCnt]=y;
}

void smtAdd(int &k,int l,int r,int x)
{
    if(!k) k=++smtCnt;
    int m=(l+r)/2;
    if(l==r)
    {
        size[k]=1;
        return ;
    }
    if(x<=m) smtAdd(nl[k],l,m,x);
    else {
        smtAdd(nr[k],m+1,r,x);
    }
    size[k]=size[nl[k]]+size[nr[k]];
}

int smtMerge(int x,int y)
{
    if(!x) return y;
    if(!y) return x;
    size[x]+=size[y];
    nl[x]=smtMerge(nl[x],nl[y]);
    nr[x]=smtMerge(nr[x],nr[y]);
    return x;
}

void dfs(int x,int ffa)
{
    l[x]=++b;
    vis[x]=1;
    smtAdd(root[x],1,n,b);
    for(int i=edgeTo[x];i;i=edgeNxt[i])
    {
        if(f[i]!=ffa)
        {
            deep[f[i]]=deep[x]+1;
            dfs(f[i],x);
        }
    }
    r[x]=b;
}

int smtQuery(int k,int l,int r,int left,int right)
{
    int m=(l+r)/2;
    if(l==left && r==right) return size[k];
    if(right<=m) return smtQuery(nl[k],l,m,left,right);
    else if (m<left) return smtQuery(nr[k],m+1,r,left,right);
        else return smtQuery(nl[k],l,m,left,m)+smtQuery(nr[k],m+1,r,m+1,right);
}
int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=q;i++)
    {
        char op[3];
        scanf("%s",op);
        scanf("%d %d",&x[i],&y[i]);
        if(op[0]=='A')
        {
            k[i]=1;
            graphAdd(x[i],y[i]);
            graphAdd(y[i],x[i]);
        }
        else k[i]=2;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i,0);
        fa[i]=i;
    }
    for(int i=1;i<=q;i++)
    {
        if(k[i]==1)
        {
            int xx=ufsSearch(x[i]),yy=ufsSearch(y[i]);
            if(deep[xx]>deep[yy]) std::swap(xx,yy);
            root[xx]=smtMerge(root[xx],root[yy]);
            fa[yy]=xx;
        }
        else
        {
            int xx=x[i],yy=y[i];
            if(deep[xx]<deep[yy])std::swap(xx,yy);
            int p=ufsSearch(xx),v=smtQuery(root[p],1,n,l[xx],r[xx]);
            printf("%lld\n",(ll)(size[root[p]]-v)*v);
        }
    }
    return 0;
}
