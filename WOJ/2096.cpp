#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct Etn
{
    int u,v,w;
}a[1000086];

int k,n;
int fa[1000086];

int gfa(int x)
{
    if(fa[x]==x) return x;
    else return gfa(fa[x]);
}

void mrg(int p,int q)
{
    int r=gfa(p);
    int s=gfa(q);
    fa[r]=s;
}

bool cmp(const Etn&a,const Etn&b)
{
    return a.w<b.w;
}
int kruskal()
{
    int tt=0,rt=0;
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        if(gfa(a[i].u)!=gfa(a[i].v))
        {
            mrg(a[i].u,a[i].v);
            rt+=a[i].w;
            tt++;
        }
        if(tt==n-1) return rt;
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        fa[i]=i;
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
        sum+=a[i].w;
    }
    printf("%d\n",sum-kruskal());
    return 0;
}

