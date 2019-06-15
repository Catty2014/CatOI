/****************************************
 * W2820 [SPJ]or
 * Segment Tree Or
 ****************************************/


#include <cstdio>

typedef long long ll;
const int N=123333;
const int INF=((2<<29)-1); //INF=1073741823
//INF=0b00111111 11111111 11111111 11111111
//Binary value after "0b"
#define lc (p<<1)
#define rc ((p<<1)|1)

int m,n;
int l[N],r[N],p[N];

struct T
{
    int l,r,lz,v;
}t[(N<<3)];

void bd(int p,int l,int r)  //Build
{
    t[p].l=l;
    t[p].r=r;
    t[p].v=INF;
    t[p].lz=INF;
    if(l==r) return;
    int m=(l+r)/2;  //"int m=(l+r)>>1;"is also avaliable 
    bd(lc,l,m);
    bd(rc,m+1,r);
    return ;
}

void pu(int p)  //Pushup
{
    t[p].v=t[rc].v|t[lc].v;  //<--OR
    return ;
}

void pd(int p)  //Pushdown
{
    if(t[p].lz==INF) return;
    t[lc].v&=t[p].lz;
    t[rc].v&=t[p].lz;
    t[lc].lz&=t[p].lz;
    t[rc].lz&=t[p].lz;
    t[p].lz=INF;
}

void add(int p,int l,int r,int v)  //add
{
    if(l<=t[p].l&&t[p].r<=r)
    {
        t[p].lz&=v;
        t[p].v&=v;
        return;
    }
    pd(p);
    int m=(t[p].l+t[p].r)/2;
    if(m>=l) add(lc,l,r,v);
    if(m<r) add(rc,l,r,v);
    pu(p);
    return;
}

int qur(int p,int l,int r)  //Query
{
    if(l<=t[p].l&&t[p].r<=r)
    {
        return t[p].v;
    }
    pd(p);
    int m=(t[p].l+t[p].r)/2;
    int ans=0;
    if(m>=l) ans|=qur(lc,l,r);
    if(m<r) ans|=qur(rc,l,r);
    pu(p);
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    bd(1,1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&l[i],&r[i],&p[i]);
        add(1,l[i],r[i],p[i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(qur(1,l[i],r[i])!=p[i])  //Answer mismatch
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",qur(1,i,i));
    }
    printf("\n");
    return 0;
}