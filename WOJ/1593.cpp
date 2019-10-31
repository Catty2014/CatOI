#include <cstdio>

int n;
const int N=233333;
int u[N],v[N];
int w[N];
const int M=10007;

int p[N],q[N],ans,mx;
long long s[N],r[N];

void deal(int u,int v)
{
    if(p[u]==0) p[u]=w[v];
    else
    {
        if(w[v]>q[u])
        {
            if(w[v]>p[u])
            {
                q[u]=p[u];
                p[u]=w[v];
            }
            else
            {
                q[u]=w[v];
            }
        }
    }
    s[u]=(s[u]+w[v]*r[u])%M;
    r[u]+=w[v];
    return ;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d %d",&u[i],&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        deal(u[i],v[i]);
        deal(v[i],u[i]);
    }
    mx=-1;
    for(int i=1;i<=n;i++)
    {
        if(p[i]*q[i]>mx) mx=p[i]*q[i];
        ans=(ans+s[i])%M;
    }
    printf("%d %d\n",mx,(ans*2)%M);
    return 0;
}
