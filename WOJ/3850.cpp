#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define mo(k) memset(k,0,sizeof(k))
#define debug(x) printf("var=%d\n",x)

int n,x,y,ans,num,tot,root,f[111],dft[111],low[111],flag[111];
struct node
{
    int u,v,nxt;
}e[23333];

void add(int u,int v)
{
    e[++num].u=u;
    e[num].v=v;
    e[num].nxt=f[u];
    f[u]=num;
}

void tarjan(int u,int fa)
{
    int son=0;
    dft[u]=low[u]=++tot;
    for(int i=f[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!dft[v])
        {
            son++;
            tarjan(v,u);
            low[u]=std::min(low[u],low[v]);
            if(low[v]>=dft[u] ) flag[u]++;
        }
        else
            if (v!=fa) low[u]=std::min(low[u],dft[v]);
        if(u==root&&son==1) flag[u]=0;
    }
}
using namespace std;

int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        mo(e);
        mo(f);
        mo(dft);
        mo(low);
        ans=num=tot=0;
        root=1;
        while(scanf("%d",&x)&&x!=0)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&y);
                add(x,y);
                add(y,x);
            }
        }
        tarjan(1,0);
        for(int i=1;i<=n;i++)
        {
            if(flag[i])
            {
                flag[i]=0;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

