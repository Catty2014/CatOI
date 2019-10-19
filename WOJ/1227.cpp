#include <cstdio>

const int N=43;

int isFirstLine,isLastColumn;
int lastX,lastY;
int g[N][N];
int n;

void refresh()
{
    isFirstLine=isLastColumn=0;
    if(lastX==1) isFirstLine=1;
    if(lastY==n) isLastColumn=1;
}

void push(int x)
{
    if(isFirstLine==0 && isLastColumn==0)
    {
        if(g[lastX-1][lastY+1]==0)
        {
            g[lastX-1][lastY+1]=x;
            lastX=lastX-1;
            lastY=lastY+1;
        }
        else
        {
            g[lastX+1][lastY]=x;
            lastX=lastX+1;
        }
    }
    if(isFirstLine==1 && isLastColumn==0)
    {
        g[n][lastY+1]=x;
        lastX=n;
        /* printf("X=%d N=%d\n",lastX,n); */
        lastY=lastY+1;
    }
    if(isFirstLine==0 && isLastColumn==1)
    {
        g[lastX-1][1]=x;
        lastX=lastX-1;
        lastY=1;
    }
    if(isFirstLine==1 && isLastColumn==1)
    {
        g[lastX+1][lastY]=x;
        lastX=lastX+1;
    }

    /* printf("LX=%d LY=%d\n",lastX,lastY); */
    refresh();
}

void show()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",g[i][j]);
        }
        printf("\n");
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d",&n);
    g[1][(n/2)+1]=1;
    lastX=1;
    lastY=(n/2)+1;
    refresh();
    for(int i=2;i<=n*n;i++)
    {
        /* printf("FL=%d LC=%d\n",isFirstLine,isLastColumn); */
        push(i);
        /* printf("FL=%d LC=%d\n",isFirstLine,isLastColumn); */
        /* for(int i=1;i<=n;i++) */
        /* { */
        /*     for(int j=1;j<=n;j++) */
        /*     { */
        /*         printf("%d",g[i][j]); */
        /*     } */
        /*     printf("\n"); */
        /* } */
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
