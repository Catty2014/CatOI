#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct SDOJ
{
    int x,y,v;
}e[23333];
int m,n,fa[M],cnt,ans;
int find(int x)
{
    return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);
}

bool cmp(SDOJ a,SDOJ b)
{
    return a.v<b.v;
}

void merge(int x,int y,int v)
{
    fa[find(x)]=find(y);
    ans+=v;
}

void ins(int x,int y,int v)
{
    cnt++;
    e[cnt].x=x;
    e[cnt].y=y;
    e[cnt].v=v;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int f,x,y,v;
        scanf("%d %d %d %d",&f,&x,&y,&v);
        if(f==1) merge(x,y,v);
        else ins(x,y,v);
    }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=cnt;++i)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if(fa[x]!=fa[y]) merge(x,y,e[i].v);
    }
    printf("%d",ans);
    return 0;
}

