#include <cstdio>
#include <vector>
#include <algorithm>

using std::min;
using std::max;

typedef long long ll;
const int N=233333;
typedef const int cint;
typedef const long long cll;
int dep[N],dfn[N];
int siz[N];
std::vector <int> e[N];
int r;//root

void dfs(cint &x,cint &p)
{
    siz[x]=1;
    dfn[x]=++dfn[0];
    dep[x]=dep[p]+1;
    for(unsigned int i=0;i<e[x].size();i++)
    {
        cint &y=e[x][i];
        if(y==p) continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}

void add(int u,int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}


class Smt
{
#define ls (p<<1)
#define rs (p<<1|1)
private:
    ll v1[N<<2],v2[N<<2];
public:
    void md(cint &p,cint &b,cint &e,cint &l,cint &r,cint &x,cll &y)
    {
        if(b==l&&e==r)
        {
            v1[p]+=x;
            v2[p]+=y;
            return ;
        }
        cint m=(b+e)>>1;
        if(l<=m) md(ls,b,m,l,min(m,r),x,y);
        if(r>m) md(rs,m+1,e,max(m+1,l),r,x,y);
    }
    ll qur(cint &p,cint &b,cint &e,cint &x)
    {
        ll ret=v1[p]*dep[x]+v2[p];
        if(b==e) return ret;
        cint m=(b+e)>>1;
        if(dfn[x]<=m) ret+=qur(ls,b,m,x);
        else ret+=qur(rs,m+1,e,x);
        return ret;
    }
}t;


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=m;i++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int u;
            scanf("%d",&u);
            printf("%lld\n",t.qur(1,1,n,u));
        }
        if(op==2)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            t.md(1,1,n,dfn[u],dfn[u]+siz[u]-1,v,v-(ll)dep[u]*v);
        }
        if(op==3)
        {
            int u;
            scanf("%d",&u);
            r=u;

        }
    }
    return 0;
}
