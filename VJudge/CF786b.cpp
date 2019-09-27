#include <cstdio>
#include <queue>

#define MID ((l+r)>>1)
typedef long long ll;

const int N=100233;
const ll inf=0x6666666666666666;

int cnt,h[N*41];

struct Tree
{
    int l,r;
}t[N*40];

int ch[N*40][2];
ll dis[N*40];
int vi[N*40];

int n,m,s,tt,r1,r2;

struct Edge
{
    int t,n,v;
}e[N*100];

void add(int u,int v,int w)
{
    cnt++;
    e[cnt].n=h[u];
    e[cnt].t=v;
    e[cnt].v=w;
    h[u]=cnt;
}

void build_1(int l,int r,int &n)
{
    if(l==r)
    {
        n=l;
        t[n].l=t[n].r=l;
        return;
    }   
    n=++tt;
    t[n].l=l;
    t[n].r=r;
    build_1(l,MID,ch[n][0]);
    build_1(MID+1,r,ch[n][1]);
    add(n,ch[n][0],0);
    add(n,ch[n][1],0);
}

void build_2(int l,int r,int &n)
{
    if(l==r)
    {
        n=l;
        t[n].l=t[n].r=l;
        return;
    }
    n=++tt;
    t[n].l=l;
    t[n].r=r;
    build_2(l,MID,ch[n][0]);
    build_2(MID+1,r,ch[n][1]);
    add(ch[n][0],n,0);
    add(ch[n][1],n,0);
}

void ln(int l,int r,int n,int nd,int k,int c)
{
    if(t[n].l>=l&&t[n].r<=r)
    {
        if(k==1) add(nd,n,c);
        else
        add(n,nd,c);
        return ;
    }
    int mid=(t[n].l+t[n].r)>>1;
    if(l>mid)
    {
        ln(l,r,ch[n][1],nd,k,c);
    }
    else if (r<=mid)
    {
        ln(l,r,ch[n][0],nd,k,c);
    }
    else
    {
        ln(l,mid,ch[n][0],nd,k,c);
        ln(mid+1,r,ch[n][1],nd,k,c);
    }
}

void sp()
{
    for(int i=1;i<=tt;i++)
    {
        dis[i]=inf;
    }
    std::queue <int> q;
    q.push(s);
    dis[s]=0;
    vi[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vi[u]=0;
        for(int i=h[u];i;i=e[i].n)
        {
            int v=e[i].t;
            if(dis[v]>dis[u]+e[i].v)
            {
                dis[v]=dis[u]+e[i].v;
                if(vi[v]==0)
                {
                    vi[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    #ifdef FILE_OUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d %d",&n,&m,&s);
    tt=n;
    build_1(1,n,r1);
    build_2(1,n,r2);
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            add(u,v,w);
        }
        if(k==2)
        {
            int u,l,r,w;
            scanf("%d %d %d %d",&u,&l,&r,&w);
            ln(l,r,r1,u,1,w);
        }
        if(k==3)
        {
            int u,l,r,w;
            scanf("%d %d %d %d",&u,&l,&r,&w);
            ln(l,r,r2,u,2,w);
        }
    }
    sp();
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==inf) printf("-1 ");
        else printf("%lld ",dis[i]);
    }
}