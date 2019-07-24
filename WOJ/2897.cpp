#include <cstdio>
#include <vector>
typedef long long ll;
typedef unsigned int uint;

const int N=100233;

int w[N],dfn[N],size[N],dep[N];

std::vector <int> e[N];

void add(const int &u,const int &v)
{
    e[u].push_back(v); 
    e[v].push_back(u);
}

void dfs (const int &x,const int &p)
{
    size[x]=1;
    dfn[x]=++dfn[0];
    dep[x]=dep[p]+1;
    for(uint i=0;i<=e[x].size();i++)
    {
        const int &y =e[x][i];
        if(y==p) continue;
        dfs(y,x);
        size[x]+=size[y];
    }
}

class SegmentTree 
{
#define ls <<1
#define rs <<1|1
private:
    ll val1[N<<2],val2[N<<2];
public:
    void mod(const int &p,const int &b,const int &e ,const int &l,const int &r,const int &x,const ll &y)
    {
        if(b==l&&e==r)
        { 
            val1[p]+=x;
            val2[p]+=x;
            return ;
        }
        const int mid=(b+e)>>1;
    }
};
