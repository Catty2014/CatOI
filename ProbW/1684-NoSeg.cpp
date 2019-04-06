#include <cstdio>
#include <iostream>

typedef long long ll;
int n=0;
ll c[233333];

inline int lbit(int x)
{
    return x&(-x);//Digit Calc Operator
}

inline void upd(int k,int v)
{
    while(k<=n)
    {
        c[k]+=v;
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
    int op,x,y;
    while(m--)
    {
        std::cin>>op>>x>>y;
        if(op=='C')
        {
            upd(x,y);
        }
        if(op=='P')
        {
            printf("%lld\n",qur(y)-qur(x-1));
        }
    }
    return 0;
}
