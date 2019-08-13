/****************************************
 * W1356,UFS
 ****************************************/
#include <cstdio>

const int N=1000233;

int n,fa[N],vi[N];

void swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}

int ffa(int x)
{
    return (x==fa[x])?fa[x]:fa[x]=ffa(fa[x]);
}

void mrg(int x,int y)
{
    if(x<y) swap(x,y);
    if(vi[y]) vi[x]=1;
    else vi[y]=1;
    fa[y]=x;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=10233;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int fx=ffa(x),fy=ffa(y);
        if(fx==fy) vi[fx]=1;
        else mrg(fx,fy);
    }
    for(int i=0;i<=10233;i++)
    {
        if(!vi[i+1])
        {
            printf("%d\n",i);
            return 0;
        }
    }
}
