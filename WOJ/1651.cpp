#include <bits/stdc++.h>
#define MX 0x7fffffff
#define MN 0x80000000
#define M 10086
#define N 233
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct exchange
{
    int u,v,w;
    exchange(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}e[M*5];

int nxt[M*5],first[M*5],n,k,cnt;
int path[M*5],ans=0,d[2*N],vis[2*N];

void addnum(int u,int v,int w)
{
    cnt++;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
}

int main()
{
    scanf("%d %d",&n,&k);
    memset()
    return 0;
}

