#include <cstdio>
#include <queue>

const int N=233333;
const int M=5333;

const int INF=0x73333333;

int n,m;
double e;
double d[N];
int vis[N];

class Edge
{
public:
    int v[N];
    double w[N];
    int f[N];
    int n[N];
    int cnt=0;
    void
    {
        cnt++;
        v[cnt]=vv;
        w[cnt]=ww;
        n[cnt]=f[uu];
        f[uu]=cnt;
    }
}a,b;

class Node 
{
public:
    double f,g;
    int u;
    bool operator < (Node p)const
    {
        if(p.f==f) return p.g<g;
        return p.f<f;
    }
};

std::queue<int> q;
void spfa(int u)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=INF;
    }
    d[u]=0;
    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=b.f[u];i;i=b.n[i])
        {
            int v=b.v[i];
            if(d[v]>d[u]+b.w[i])
            {
                d[v]=d[u]+b.w[i];
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

std::priority_queue<Node> Q;
int aStar(int u,int v)
{
    int cnt=0;
    double ans=0.0;
    Node t;
    t.u=u;
    t.g=0.0;
    t.f=d[u];
    Q.push(t);
    while(!Q.empty())
    {
        t=Q.top();
        Q.pop();
        if(ans>e) return cnt-1;
        if(t.u==v) 
        {
            cnt++;
            ans+=t.f;
            continue;
        }
        for(int i=a.f[t.u];i;i=a.n[i])
        {
            Node vv;
            vv.u=a.v[i];
            vv.g=t.g+a.w[i];
            vv.f=vv.g+d[vv.u];
            Q.push(vv);
        }
    }
    return cnt;
}



int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d %lf",&n,&m,&e);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        double w;
        scanf("%d %d %lf",&u,&v,&w);
        a.addEdge(u,v,w);
        b.addEdge(u,v,w);
    }
    spfa(n);
    int ans=aStar(1,n);
    printf("%d\n",ans);
    return 0;
}
