#include<cstdio>
#include<cstring>
typedef long long ll;
const int MOD=1e9+7;
const int N=5;

struct Matrix
{
    ll a[N][N];
    int n;
    Matrix(int num)
    {
        memset(a,0,sizeof(a));
        n=num;
    }
    friend Matrix operator * (Matrix A,Matrix B);
    friend Matrix operator ^ (Matrix A,ll p);
}A(3),B(3);

Matrix operator * (Matrix A,Matrix B)
{
    Matrix C(3);
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
}

Matrix operator ^ (Matrix A,ll p)
{
    Matrix C(3);
    for(int i=1;i<=C.n;i++)
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
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    if(n==1) n++;
    A.a[1][1]=1;
    A.a[1][2]=1;
    B.a[1][1]=1;
    B.a[1][2]=1;
    B.a[2][1]=1;
    //printf("balalala");
    B=B^(n-2);
    A=A*B;
    printf("%d",A.a[1][1]);
    return 0;
}
