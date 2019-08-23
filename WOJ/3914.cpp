#include <cstdio>

typedef long long ll;
const int N=5833;
const int I=0x73333333;
int m,n,ans;
int b[23333];
int c[4][N];

void div(int q,int e)
{
    for(int i=2;i*i<=q;i++)
    {
        while(q%i==0)
        {
            b[i]+=e;
            q/=i;
            if(q!=1) b[q]+=e;
        }
    }
}

void mul(int q,int w,int e)
{
    for(int i=1;i<=c[0][0];i++)
    {
        c[0][i]=0;
    }
    c[0][0]=c[q][0]+c[w][0]-1;
    for(int i=1;i<=c[q][0];i++)
    {
        for(int j=1;j<=c[w][0];j++)
        {
            c[0][i+j-1]+=c[w][j]*c[q][i];
            c[0][i+j]+=c[0][i+j-1]/10;
            c[0][i+j-1]%=10;
        }
    }
    while(c[0][c[0][0]+1])
    {

    }
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int q,w;
    scanf("%d %d",&n,&m);
    if(n==0)
    {
        printf("1\n");
        return 0;
    }
    return 0;
}
