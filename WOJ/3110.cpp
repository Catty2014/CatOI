#include <cstdio>

const int N=52333;
#define lb ((p)&(-p))

int c[N];

void upd(int p,int v)
{
    while(p<=N)
    {
        c[p]+=v;
        p+=lb;
    }
}

int qur(int p)
{
    int x=0;
    while(p)
    {
        x+=c[p];
        p-=lb;
    }
    return x;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int ls=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        upd(i,t-ls);
        ls=t;
    }
    for(int i=1;i<=n;i++)
    {
        int op,l,r,cc;
        scanf("%d %d %d %d",&op,&l,&r,&cc);
        if(op==1)
        {
            printf("%d\n",qur(r));
        }
        if(op==0)
        {
            upd(l,cc);
            upd(r+1,-cc);
        }
    }
    return 0;
}
