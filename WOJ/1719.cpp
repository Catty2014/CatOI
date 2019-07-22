#include <cstdio>
#include <iostream>

using std::cin;

#define lbit(x) ((x)&(-x))
int n;
int c[133333];

inline void _add(int k,int v)
{
    while(k<=n)
    {
        c[k]+=v;
        k+=lbit(k);
    }
    return ;
} 

inline int qur(int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=c[k];
        k-=lbit(k);
    }
    return ans;
}

inline void prt(int k)
{
    k=k%2;
    if(k==1) printf("no\n");
    else printf("yes\n");
    return ;
}

int main(int argc, char const *argv[])
{
    int m;//N:Card M:Query
    scanf("%d %d",&n,&m);
    while(m--)
    {
        char op;
        cin>>op;
        if(op=='Q')
        {
            int tg;
            scanf("%d",&tg);
            prt(qur(tg));
        }
        if(op=='T')
        {
            int l,r;
            scanf("%d %d",&l,&r);
            _add(l,1);
            _add(r+1,-1);
        }
    }
    return 0;
}
