#include <cstdio>

#define lb ((x)&(-x))

const int N=233333;

struct Edg
{
    int t,n;
}e[N];

int tt,h[N];
int in[N],vi[N];
int n,m;
int cnt;
int out[N],c[N];

void _ade(int u,int v)
{
    tt++;
    e[tt].t=v;
    e[tt].n=h[u];
    h[u]=tt;
}

void dfs(int x)
{
    in[x]=++cnt;
    vi[x]=1;
    for(int i=h[x];i;i=e[i].n)
    {
        if(vi[e[i].t]==0) dfs(e[i].t);
    }
    out[x]=cnt;
}

void upd(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lb;
    }
}

int qur(int x)
{
    int ans=0;
    while(x>0){
        ans+=c[x];
        x-=lb;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        _ade(a,b);
        _ade(b,a);
    }
    dfs(1);
    for(int i = 1; i <=n; i++)
    {
        upd(in[i],1);
        vi[i]=1;
    }
    scanf("%d",&m);
    for(int i = 1; i <=m; i++)
    {
        char op[3];
        int x;
        scanf("%s%d",op,&x);
        // printf("%c\n",op[0]);
        if(op[0]=='C')
        {
            if(vi[x]) upd(in[x],-1);
            else
            {
                upd(in[x],1);
            }
            vi[x]=1-vi[x];
        }
        if(op[0]=='Q')
        {
            printf("%d\n",qur(out[x])-qur(in[x]-1));
        }
    }
    return 0;
}