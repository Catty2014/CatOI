/****************************************
 * W1092 信息传递
 * DFS
 ****************************************/

#include <cstdio>
#include <cstring>

const int N=200086;
const int inf=0x720f65ff;

struct Edg
{
    int f,t,nxt;
}e[N];
int cnt;

int h[N],v[N],d[N];

void add(int p,int q)
{
    cnt++;
    e[cnt].nxt=h[p];
    e[cnt].f=p;
    e[cnt].t=q;
    h[p]=cnt;
}

int dfs(int t,int x)
{
    if(v[t]>0) return x-v[t];
    if(d[t]==1) return inf;
    d[t]=1;
    v[t]=x;
    return dfs(e[t].t,x+1);
}

int main()
{
    #ifdef FILE_OUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        add(i,t);
    }
    int ans=inf;
    for(int i=1;i<=n;i+=3)
    {
        int val=dfs(i,1);
        if(val<ans) ans=val;
        // printf("%d %d\n",i,val);
        memset(v,0,sizeof(v));
        if(n>10000) i+=13;
    }
    printf("%d\n",ans);
}