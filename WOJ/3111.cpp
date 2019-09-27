#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const int N=52333;
const int M=533;

int n,blk;
int v[N],l[N],t[N];
std::vector <int> e[M];

void reset(int x)
{
    e[x].clear();
    for(int i=(x-1)*blk+1;i<=std::min(x*blk,n);i++)
    {
        e[x].push_back(v[i]);
    }
    std::sort(e[x].begin(),e[x].end());
}

void add(int a,int b,int c)
{
    for(int i=a;i<=std::min(l[a]*blk,b);i++)
    {
        v[i]+=c;
    }
    reset(l[a]);
    if(l[a]!=l[b])
    {
        for(int i=(l[b]-1)*blk+1;i<=b;i++)
            v[i]+=c;
        reset(l[b]);
    }
    for(int i=l[a]+1;i<=l[b]-1;i++)
        t[i]+=c;
}

int query(int a,int b,int c)
{
    int ans=0;
    for(int i=a;i<=std::min(l[a]*blk,b);i++)
        if(v[i]+t[l[a]]<c) ans++;
    if(l[a]!=l[b])
    {
        for(int i=(l[b]-1)*blk+1;i<=b;i++)
        {
            if(v[i]+t[l[b]]<c) ans++;
        }
    }
    for(int i=l[a]+1;i<=l[b]-1;i++)
    {
        int x=c-t[i];
        ans+=std::lower_bound(e[i].begin(),e[i].end(),x)-e[i].begin();
    }
    return ans;
}

int main(void)
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    blk=std::sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        l[i]=(i-1)/blk+1;
        e[l[i]].push_back(v[i]);
    }
    for(int i=1;i<=l[n];i++)
    {
        std::sort(e[i].begin(),e[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        int op,a,b,c;
        scanf("%d %d %d %d",&op,&a,&b,&c);
        if(op==0) add(a,b,c);
        if(op==1) printf("%d\n",query(a,b,c*c));
    }
    return 0;
}
