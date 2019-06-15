//2333
//你把我开了试试?idw?
//反正这周作业还多
//F A Q

//This is a template

#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=33;
const int MOD=1e9+7;

struct Matrix
{
    ll a[N][N];
    int n;
    Matrix(int num)
    {
        memset(a,0,sizeof(a));
        n=num;
    };
    friend Matrix operator * (Matrix A,Matrix B);
    friend Matrix operator ^ (Matrix A,ll p);
}A(32);

Matrix operator * (Matrix A,Matrix B)
{
    Matrix C(32);
    for(int i=1;i<=A.n;i++)
    {
        for(int k=1;k<=A.n;k++)
        {
            for(int j=1;j<=A.n;j++)
            {
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%MOD)%MOD;
            }
        }
    }
    return C;
};

Matrix operator ^ (Matrix A,ll p)
{
    Matrix C(32);
    for(int i=0;i<=C.n;i++)
    {
        C.a[i][i]=1;
    }
    while(p)
    {
        if(p&1) C=C*A;
        p>>=1;
        A=A*A;
    }
    return C;
};

int main(int argc, char const *argv[])
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&A.a[i][j]);
        }
    }
    A=A^n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",A.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
