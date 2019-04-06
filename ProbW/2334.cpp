/******************************
 * WOJ #2334 树的直径 
 * Using Double_DFS
 ******************************/
#include <cstdio>

int n;
int d[13333];
int ans=0;
int cnt;
int fi[13333];
int st;

struct Edg
{
    int v,w,nxt;
}e[13333];

void dfs(int x,int f)
{
    if(d[x]>ans) 
    {
        ans=d[x];
        st=x;
    }
    for(int i=fi[x];i;i=e[i].nxt)
    {
        int y=e[i].v;
        if(y==f) continue;
        d[y]=d[x]+e[i].w;
        dfs(y,x);
    }
    return ;
}

void Edga(int x,int y,int z)
{
    cnt++;
    e[cnt].v=y;
    e[cnt].w=z;
    e[cnt].nxt=fi[x];
    fi[x]=cnt;
    return ;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        Edga(x,y,z);
        Edga(y,x,z);
    }
    //DFS1
    st=1;
    d[1]=0;
    dfs(1,0);
    //DFS2
    d[st]=0;
    ans=0;
    dfs(st,0);
    printf("%d\n",ans);
    return 0;
}