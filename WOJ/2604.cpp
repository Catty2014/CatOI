#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
const int N=100233;
typedef long long ll;
const ll INF=0x7333333333333333;
ll low[N],dfn[N],first[N],head[N],vis[N],col[N],v[N],u[N],w[N],t[N],d[N];
ll n,m,dep,cnt,gro,cot;
struct email
{
    ll u,v,w;
    ll nxt;
}e[N*4],g[N*4];
std::queue<ll>q;
std::stack<ll>s;
inline void add(ll u,ll v,ll w)
{
    e[++cnt].nxt=first[u];first[u]=cnt;
    e[cnt].u=u;e[cnt].v=v;e[cnt].w=w;
}

inline void readd(ll u,ll v,ll w)
{
    g[++cot].nxt=head[u];head[u]=cot;
    g[cot].u=u;g[cot].v=v;g[cot].w=w;
}

void spfa(ll x)
{
    q.push(x);vis[x]=1;t[x]=0;d[x]=0;
    while(!q.empty())
    {
        ll u=q.front();q.pop();vis[u]=0;
        for(ll i=head[u];i;i=g[i].nxt)
        {
            ll v=g[i].v,tim=g[i].w,w=e[i].w;
            if(t[v]>t[u]+tim)
            {
                t[v]=t[u]+tim;
                d[v]=d[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
            if(t[v]==t[u]+tim)
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=1;
                    }

                }    
        }
    }
}

void tarjan(ll u)
{
    low[u]=dfn[u]=++dep;
    s.push(u);vis[u]=1;
    for(ll i=first[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }
        else
            if(vis[v])
                low[u]=std::min(low[u],dfn[v]);    
    }
    if(dfn[u]==low[u])
    {
        gro++;
        while(1)
        {
            ll tt=s.top();s.pop();
            col[tt]=gro;
            vis[tt]=0;
            if(tt==u)break;
        }
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
        add(v[i],u[i],w[i]);
    }
    tarjan(1);
    for(ll i=1;i<=m;i++)
    {
        ll u1=u[i],v1=v[i],w1;
        if(col[u1]==col[v1])
            w1=1;
        else
            w1=0;
        readd(v1,u1,w1);
    }
    memset(vis,0,sizeof(vis));
    for(ll i=1;i<=n;i++)
        t[i]=INF,d[i]=INF;
    spfa(1);
    for(ll i=2;i<=n;i++)
    {
        if(t[i]==INF||d[i]==INF)
            printf("-1\n");
        else
            printf("%lld %lld\n",t[i],d[i]);
    }

}
