#include <cstdio>
#include <cstdlib>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef long long ll;
const int N=2333333;
const int M=2*N;
const ll INF=0x5f5f5f5f5f5f5f5f;
const ll FNI=0x9000000000000000;

int n,m;

struct Edg
{
    int to,w,nx;
}e[M];
int e_cnt;
int fir[N];
int w[N],f[N];
bool vi[N],vis[N],vir[N];
ll tt,co[N],sum[N],di[N];
ll _min=INF,_max=FNI,ret;
int pr[N],prw[N];

void add(int u,int v,int w)
{
    e_cnt++;
    e[e_cnt].to=v;
    e[e_cnt].w=w;
    e[e_cnt].nx=fir[u];
    fir[u]=e_cnt;
}

bool dfs(int x)
{
    vis[x]=1;
    for(int i=fir[x];i;i=e[i].nx)
    {
        int v=e[i].to;
        if(vir[i]||vir[i^1]) continue;
        vir[i]=vir[i^1]=1;
        if(vis[v])
        {
            tt++;
            co[tt]=v;
            int tmp=e[i].w;
            vi[v]=1;
            for(int u=x;u!=v;u=pr[u])
            {
                ++tt;
                co[tt]=u;
                sum[tt]=tmp;
                tmp=prw[u];
                vi[u]=1;
            }
            sum[1]=tmp;
            return 1;
        }
        pr[v]=x;
        prw[v]=e[i].w;
        if(dfs(v)) return true;
    }
    return false;
}

void loop(int x)
{
    int u;
    for(u=f[x];!vis[u];u=f[u])
    {
        vis[u]=1;
    }
    int tmp=w[u];
    co[++tt]=u;
    vi[u]=1;
    for(u=f[u];!vi[u];u=f[u])
    {
        co[++tt]=u;
        sum[tt]=tmp;
        tmp=w[u];
        vi[u]=1;
    }
    sum[1]=tmp;
}

void dp(int x)
{
    vi[x]=1;
    for(int i=fir[x];i;i=e[i].nx)
    {
        int v=e[i].to;
        if (vi[v]) continue;
        dp(v);
        ret=max(ret,di[x]+di[v]+e[i].w);
        di[x]=max(di[x],di[v]+e[i].w);
    }
}

ll sol(int x)
{
    tt=0;
    _min=INF;
    _max=-INF;
    ret=0;
    dfs(x);
    for(int i=1;i<=tt;i++)
    {
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=tt;i++)
    {
        dp(co[i]);
    }
    for(int i=1;i<=tt;i++)
    {
        ret=max(ret, max(sum[i]+di[co[i]]-_min,sum[tt]-sum[i]+di[co[i]]+_max) );
        _min=min(_min,sum[i]-di[co[i]]);
        _max=max(_max,sum[i]+di[co[i]]);
    }
    return ret;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int siz=134217728;//64M?
    __asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(siz)+siz));//Linux

    //话说我可以用ulimit呀

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&f[i],&w[i]);
        add(f[i],i,w[i]);
        add(i,f[i],w[i]);
    }
    ll ans=0x00;
    for(int i=1;i<=n;i++)
    {
        if(!vi[i])
        {
            ans+=sol(i);
        }
    }
    printf("%lld\n",ans);
    exit(0);
    return 0;
}
