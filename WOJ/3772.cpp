/****************************************
 * W3772 位运算
 * Segment Tree..?
 * Violence
 ****************************************/

#include <cstdio>

#define max(a,b) ((a>b)?a:b);

int q;

int Q[1233333];
int qn;

void qurn(int v)
{
    int m=0,n=0,t=0;
    for(int i=1;i<=qn;i++)
    {
        m=max(m,(v^Q[i]));
        n=max(n,(v&Q[i]));
        t=max(t,(v|Q[i]));
    }
    printf("%d %d %d\n",m,n,t);
}

int main()
{
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int op,v;
        scanf("%d %d",&op,&v);
        if(op==1)
        {
            Q[(++qn)]=v;
        }
        if(op==2)
        {
            qurn(v);
        }
    }
    return 0;
}