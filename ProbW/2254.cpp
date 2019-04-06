#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

struct Edge
{
    int from,to,next;
}edge[M];
int dfn[M],low[M];
int ldx;
int h[M];
queue <Edge> stk;
void dfs(int u,int pre)
{
    dfn[u]=low[u]=++ldx;
    for(int i=h[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        if(!dfn[v])
        {
            stk.push(edge[i]);
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v])
            {
                Edge tmp;
                int cnt=0;
                bcc.clear();
                do{
                    cnt++;
                    tmp=stk.top();
                    stk.pop();
                    bcc.insert(tmp.from);
                    bcc.insert(tmp.to);
                }while(tmp.from!=u||tmp.to!=v);
                if(cnt>bcc.sice()) ans+=cnt;

            }
            if(low[v]>dfn[u])++cnt;

        }
        else if  (dfn[v]<dfn[u])
        {
            stk.push(edge[i]);
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main()
{

    return 0;
}

