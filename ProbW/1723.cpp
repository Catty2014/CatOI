#include <cstdio>

typedef long long ll;
ll c[233333],a[233333];
int n=0;

inline int lbit(int x)
{
    return x&(-x);
}

inline void add(int k,int x)
{
    while(k<=n)
    {
        c[k]+=x;
        k+=lbit(k);
    }
    return ;
}

inline ll qur(int k)
{
    ll ret=0;
    while(k>0)
    {
        ret+=c[k];
        k-=lbit(k);
    }
    return ret;
}


int main()
{
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        add(i,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++)
    {
        int op=0;
        scanf("%d",&op);
        if(op==1)
        {
            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        if(op==2)
        {
            int p;
            scanf("%d",&p);
            printf("%d\n",qur(p));
        }
    }
    return 0;
}
