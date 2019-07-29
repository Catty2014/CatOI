#include <cstdio>

const int N=140;
const int M=1680;

struct Edg
{
    int nx,to;
}e[M];
int e_cnt;
int fi[M];
int n,m;

struct SW
{
    int n,d,v,w;
    int dfn;
}s[N];

void add(int u,int v)
{
    e_cnt++;
    e[e_cnt].to=v;
    e[e_cnt].nx=fi[u];
    fi[u]=e_cnt;
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
        scanf("%d",&s[i].w);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].v);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].d);
        if(s[i].d!=0)
        {
            add(s[i].d,i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i].dfn!=0)
        {
            tj(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!s[i].d || s[i].d==s[s[i].d].d)
        {
            continue;
        }
        add(s[i].d,s[s[i].d].d);
        //...
    }
    return 0;
}
