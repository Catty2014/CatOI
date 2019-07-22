#include<cstdio>
#include<cstring>
typedef long long ll;
const int MOD=1e9+7;
const int N=7;

struct Matrix
{
    int n;
    int m;
    ll a[N][N];
    Matrix(int num,int tmp)
    {
        memset(a,0,sizeof(a));
        n=num;
        m=tmp;
    }
    friend Matrix operator * (Matrix A,Matrix B);
    friend Matrix operator ^ (Matrix A,ll p);
};

Matrix operator * (Matrix A,Matrix B)
{
    Matrix C(4,A.m);
    for(int i=1;i<=A.n;i++)
    {
        for(int k=1;k<=A.n;k++)
        {
            for(int j=1;j<=A.n;j++)
            {
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%A.m)%A.m;
            }
        }
    }
    return C;
}

Matrix operator ^ (Matrix A,ll p)
{
    Matrix C(4,A.m);
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
//f(x)=f(x-1)+f(x-3)+f(x-4)
//f(1)=2
//f(2)=4
//f(3)=6
//f(4)=9
//B:
//1 1 0 0
//0 0 1 0
//1 0 0 1 
//1 0 0 0
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll l,m;
        scanf("%lld %lld",&l,&m);
        Matrix A(4,m),B(4,m);
        A.a[1][4]=2;
        A.a[1][3]=4;
        A.a[1][2]=6;
        A.a[1][1]=9;
        B.a[1][1]=1;
        B.a[1][2]=1;
        B.a[2][3]=1;
        B.a[3][1]=1;
        B.a[3][4]=1;
        B.a[4][1]=1;
        if(l<=4)
        {
            printf("%lld\n",A.a[1][l]%m);
            continue;
        }
        B=B^(l-4);
        A=A*B;
        /* for(int i=1;i<=6;i++) */
        /* { */
        /*     for(int j=1;j<=6;j++) */
        /*     { */
        /*         printf("%lld ",A.a[i][j]); */
        /*     } */
        /*     printf("\n"); */
        /* } */
        printf("%lld\n",A.a[1][1]);
    }
    return 0;
}
