
#include<iostream> 
using namespace std; 
const int maxn=210100; 
struct node { 
    int to; int next; 
}e[maxn]; 
char s;int x; 
int in[maxn],out[maxn],c[maxn],cnt; 
int n,m,tot,head[maxn],vis[maxn]; 
void edd_edge(int u,int v)
{ 
    tot++;
    e[tot].to=v; 
    e[tot].next=head[u]; 
    head[u]=tot; 
} 
int lowbit(int x)
{ 
    return x&(-x);
} 
void dfs(int x) 
{
    in[x]=++cnt;
    for(int i=head[x];
    i;i=e[i].next) dfs(e[i].to); 
    out[x]=cnt;
} 
void update(int x,int add)
{
    while(x<=n) 
    { 
        c[x]+=add; 
        x+=lowbit(x);
    } 
} 
int sum(int x)
 { 
    int s=0; 
    while(x>0)
    { 
        s+=c[x];
        x-=lowbit(x);
    } 
    return s; 
 }
 int main()
{ 
    int a,b;
    cin>>n; 
    for(int i=1;i<n;i++)
    { 
        cin>>a>>b;
        edd_edge(a,b); 
    } 
    dfs(1);
    for(int i=1;i<=n;i++) 
        update(in[i],1),vis[i]=1; 
    cin>>m; 
    for(int i=1;i<=m;i++)
    { 
        cin>>s>>x; 
        if(s=='C')
        {
            if(vis[x])update(in[x],-1);
            else
            update(in[x],1); vis[x]=1-vis[x];
        } 
        if(s=='Q')
        cout<<sum(out[x])-sum(in[x]-1)<<endl;
        }
    return 0; 
}
