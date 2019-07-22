#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define inf 1<<30
#define mod 1000000007
#define N 100010
using namespace std;
struct edge
{
    int v,w,next;
    edge(){}
    edge(int v,int w,int next):v(v),w(w),next(next){}
}e[N<<1];
int head[N],vis[N],nor[N],tot;
void addedge(int u,int v,int w)
{
    e[tot]=edge(v,w,head[u]);
    head[u]=tot++;
}
void dfs(int u,int w)
{
    vis[u]=1;nor[u]=w;
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].v;
        if(vis[v])continue;
        dfs(v,e[i].w^w);
    }
}
struct Trie
{
    int next[N<<4][2];
    int root,L;
    int newnode()
    {
        next[L][0]=next[L][1]=-1;
        return L++;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(int x)
    {
        int now=root;
        for(int i=30;i>=0;i--)
        {
            int num=(1<<i)&x?1:0;
            if(next[now][num]==-1)
                next[now][num]=newnode();
            now=next[now][num];
        }
    }
    int find(int x)
    {
        int now=root,res=0;
        for(int i=30;i>=0;i--)//从二进制的第31位到第1位查找最大异或值
        {
            int num=(1<<i)&x?0:1;//获取num的二进制数的第i+1位上的数字的非
            if(next[now][num]!=-1)//如果字典树有要查找的数即有相异的数
            {
                res|=1<<i;//加上该位的权值
                now=next[now][num];//进入下一层
            }
            else now=next[now][!num];//如果没有，则按num当前位上的数字进入下一层查找
        }
        return res;
    }
}trie;
int main()
{
    int n,u,v,w;
    int ori;
    while(scanf("%d",&n)>0)
    {
        scanf("%d",&ori);
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        tot=0;trie.init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dfs(0,0);
        int ans=0,mx;
        for(int i=0;i<n;i++)
        {
            trie.insert(ori^nor[i]);
            mx=trie.find(ori^nor[i]);
            ans=max(ans,mx);
        }
        printf("%d\n",ans);
    }
}
