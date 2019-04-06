//QAQ不会啊

#include <cstdio>
#include <cstring>
struct G
{
    int next[233];
    int t;
    int a;
    bool color;
    bool valid;
}g[2333];

bool dfs(int k)
{
    if(g[k].color==1) return 0;
    if(g[k].valid==0) return 0;
    if(g[k].t==0 )return 0;
    g[k].color=1;
    for(int i=1;i<=g[k].t;i++)
    {
        dfs(g[k].next[i]);
    }
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("starwar.in","r",stdin);
    freopen("starwar.out","w",stdout);
    #endif
    int M,N;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        int _1,_2;
        scanf("%d %d",&_1,&_2);
        g[_1].next[++g[_1].t]=_2;
        g[_2].next[++g[_2].t]=_1;
        g[_1].valid=1;
        g[_2].valid=1;
    }
    int ans=0;
    int tmp;
    while(scanf("%d",&tmp)!=EOF)
    {
        g[tmp].t=0;
        for(int i=0;i<=100;i++)
        {
            g[i].color=0;
        }
        for(int j=0;j<=100;j++)
        {
            if(dfs(j)) ans++;
        }
        printf("%d\n",ans);
        ans=0;
    }
}