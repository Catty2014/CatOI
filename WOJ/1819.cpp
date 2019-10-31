//就这货的效率，真的能过?
#include <cstdio>
#include <cstring>

int n,m;

const int N=1e6+2333;

struct Query
{
    int n,l,r;
}q[N];

int a[N];

int b[N];
int s[N];
int chk(int p)
{
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    for(int i=1;i<=p;i++)
    {
        b[q[i].l]+=q[i].n;
        b[q[i].r+1]-=q[i].n;
    }
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+b[i];
        if(s[i]>a[i])
        {
            return 0;
        }
    }
    return 1;
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
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&q[i].n,&q[i].l,&q[i].r);
    }
    if(chk(n)==1)
    {
        printf("0\n");
        return 0;
    }
    int l=1,r=m;
    while(l<r-1)
    {
        int m=(l+r)>>1;
        if(chk(m)) l=m+1;
        else r=m;
    }
    printf("-1\n%d\n",(chk(l))?r:l);
    return 0;
}
