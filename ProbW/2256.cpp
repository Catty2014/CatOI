/****************************************
 * W2256 [HDU3018]Ant Trip
 * Union Set Ex
 * Eular Path
 ****************************************/

#include <cstdio>
#include <cstring>

const int N=233333;

int n,m;
int fa[233333];
int d[133333];
int nm[233333];
int odd[N];

int ffa(int i)
{
   if(fa[i]==0) fa[i]=i;
   if(fa[i]!=i) fa[i]=ffa(fa[i]);
   return fa[i];
}

int main()
{
    while(scanf("%d %d",&n,&m)!=(-1))
    {
        memset(odd,0,sizeof(odd));
        memset(nm,0,sizeof(nm));
        memset(fa,0,sizeof(fa));
        memset(d,0,sizeof(d));
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            d[u]++;
            d[v]++;
            u=ffa(u);
            v=ffa(v);
            if(u!=v) fa[u]=v;
        }
        for(int i=1;i<=n;i++)
        {
            nm[ffa(i)]++;
            if(d[i]%2==1) odd[ffa(i)]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(nm[i]<=1) continue;
            if(odd[i]==0) ans++;
            if(odd[i]>=1) ans+=odd[i]/2;
        }
        printf("%d\n",ans);
    }
}