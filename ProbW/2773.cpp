/****************************************
 * W2773 银河英雄传说
 * Union Set Ex
 ****************************************/

#include <cstdio>

const int N=32333;

#define abs(x) ((x>=0)?x:(-x))

int cn[N],fa[N],bf[N];
int t;

int ffa(int i);

void mrg(int x,int y)
{
    int i;int j;
    i=ffa(x);
    j=ffa(y);
    fa[i]=j;
    bf[i]=bf[i]+cn[j];
    cn[j]+=cn[i];
}

int ffa(int i)
{
    int f;
    if(fa[i]==0) fa[i]=i;
    if(fa[i]==i) return i;
    f=ffa(fa[i]);
    bf[i]+=bf[fa[i]];
    fa[i]=f;
    return fa[i];
}

void qur(int x,int y)//[x,y]
{
    if(ffa(x)!=ffa(y)) printf("-1 \n");
    else printf("%d \n",abs((bf[x]-bf[y]))-1);
    return ;
}

int main()
{
    char chr;
    scanf("%d%c",&t,&chr);
    for(int i=1;i<=t;i++)
    {
        char op;
        int x,y;
        scanf(" %c %d %d%c",&op,&x,&y,&chr);
        if(cn[x]==0) cn[x]=1;
        if(cn[y]==0) cn[y]=1;
        if(op=='M') mrg(x,y);
        if(op=='C') qur(x,y);
    }
    return 0;
}