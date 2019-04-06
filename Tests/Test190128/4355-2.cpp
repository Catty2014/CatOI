//出题人还是太懒...

#include <algorithm>
#include <cstdio>

using std::min;
typedef long long ll

const int N=101000;
struct Edge{int v,nxt;}e[N];
int a[N],chs[N],head[N];
int n,_;ll k;

const ll lim=1e18;

struct node{
    int v;ll c;
    inline node(){}
    friend inline void operator + (node&A,const node B){
        if(A.v<B.v)A.v=B.v,A.c=B.c;
        else if(A.v==B.v)A.c=min(lim,A.c+B.c);
    }
}d[N],g[N],cl;

#define lb(x) (x&(-x))

inline node qy(int x)
{
    node p=cl;
    for(x;x<=n+1;x+=lb(x))
        p+d[x];
    return p;
}
inline void add(int x,node y)
{
    for(;x;x-=lb(x))d[x]+y;
}
inline void ae(int u,int v)
{
    e[++_].v=v;
    e[_].nxt=head[u];
    head[u]=_;
}

int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    cl.c=1,add(n+1,cl),cl.c=0;
    for(int i=n;i;--i)
    {
        g[i]=qy(a[i]);
        ++g[i].v;
        add(a[i],g[i]);
    }
    for(int i=n;i;--i)ae(g[i].v,i);
    for(int stp=qy(1).v,R=0;stp;--stp)
    for(int i=head[stp],v;i;i=e[i].nxt)
    {
        v=e[i].v;
        if(g[v].c<k)k-=g[v].c;
        else {
            chs[a[v]]=true;
            while(R<v)g[R++]=cl;
            break;
        }
    }
    printf("%d\n",n-qy(1).v);
    for(int i=1;i<=n;++i)
        if(!chs[i])printf("%d\n",i);
    return 0;
}