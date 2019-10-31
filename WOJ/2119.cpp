#include <cstdio>
int n;
int m;
const int N=2333;
int f[N];
int v[N];

int ufsFind(int x)
{
    if(f[x]==x) return f[x];
    else return f[x]=ufsFind(f[x]);
}

void ufsJoin(int x,int y)
{
    int fx=ufsFind(x);
    int fy=ufsFind(y);
    if(fx!=fy)
    {
        f[fx]=fy;
    }
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        ufsJoin(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(v[ufsFind(i)]==0)
        {
            v[ufsFind(i)]=1;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
