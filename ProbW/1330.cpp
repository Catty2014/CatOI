//...
#include <cstdio>

int n,m,k;
int cnt;
int h[40333],fa[40333];

struct Edg
{
    int nxt,to,d;
}e[80333];

void bd(int n,int t,int d)
{
    cnt++;
    e[cnt].nxt=h[n];
    e[cnt].to=t;
    e[cnt].d=d;
    h[n]=cnt;
}

int ffa(int x)
{
    if(x!=fa[x]) fa[x]=ffa(x);
    return fa[x];
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int p,q,v;
        char tmp;//It's useless!!
        scanf("%d %d %d %c",&p,&q,&v,&tmp);
        bd(p,q,v);
        bd(q,p,v);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        
    }
    return 0;
}