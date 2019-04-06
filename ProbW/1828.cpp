#include<cstdio>
const int N=1010;
const int P=10007;

int n,m,a,b,k,c[N][N];

void yh() //YangHuiTriangle
{
    a%=P;
    b%=P;
    c[0][0]=1;
    c[1][0]=b;
    c[1][1]=a;
    for(int i=2;i<=k;i++)
    {
            for(int j=0;j<=i&&j<=n;j++)
            {
                c[i][j]=c[i-1][j]*b%P;
                if(j) c[i][j]=(c[i][j]+c[i-1][j-1]*a)%P;
            }
    }
}
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    yh();
    printf("%d\n",c[k][n]);
    return 0;
}