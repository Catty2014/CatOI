/* LDWOJ #2698 走迷宫*/

#include <cstdio>
#include <cstring>

int m,n;
int a[2018][2018];
int d[2018],g[2018];
bool vis[2019];

void djstr(int s)
{
    int i,j,k,_max;
    for(int i=0;i<=n;i++)
    {
        d[i]=0x3f3f3f3f;
    }
    d[s]=0;
    g[s]=1;
    for(i=1;i<=n;i++)
    {
        _max=0x3f3f3f3f;
        k=0;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&d[j]<_max) 
            {
                _max=d[j];
                k=j;
            }
            if(d[k]==0x3f3f3f3f) return ;
            vis[k]=1;
            for(j=1;j<=n;j++)
            {
                if(!vis[j]&&a[k][j]!=0x3f3f3f3f)
                {
                    if(d[j]==d[k]+a[k][j]) g[j]+=g[k];
                    if(d[j]>d[k]+a[k][j]) 
                    {
                        d[j]=d[k]+a[k][j];
                        g[j]=g[k];
                    }
                }
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int k,b,v;
        scanf("%d %d %d",&k,&b,&v);
        a[k][b]=v;
    }
    djstr(1);
    printf("%d %d\n",d[n],g[n]);
    return 0;
}