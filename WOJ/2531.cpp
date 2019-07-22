
#include<cstdio> 
#include<cstring>

#define MIN(a,b) ((a<b)?a:b)

const int N=2005;
int n,first[N],f[N][3],cnt=0,w[N],rt; 
bool vis[N]; 

struct edge
{
    int v,next;
}e[N]; 

void add(int u,int v)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].next=first[u];
    first[u]=cnt;
    return ;
} 

int dfs(int p,int k)
{ 
    if(~f[p][k]) return f[p][k]; 
    f[p][k]=(k==0)?w[p]:(k==1?0:2e9); 
    for(int i=first[p];i;i=e[i].next)
    { 
        int v=e[i].v; 
        if(!k)f[p][k]+=MIN(dfs(v,0),MIN(dfs(v,1),dfs(v,2))); 
        else 
            if(k==1)f[p][k]+=MIN(dfs(v,0),dfs(v,2)); 
            else 
                f[p][k]=MIN(f[p][k],dfs(p,1)-MIN(dfs(v,0),dfs(v,2))+f[v][0]); 
    } 
    return f[p][k]; 
} 

int main()
{ 
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;++i)
    { 
        int u,v,k; 
        scanf("%d %d %d",&u,&w[u],&k);
        for(int j=1;j<=k;++j)
        scanf("%d",&v);
        add(u,v),vis[v]=true;
    } 
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            rt=i;
            break;
        } 
    printf("%d\n",MIN(dfs(rt,0),dfs(rt,2)));
    return 0; 
}
