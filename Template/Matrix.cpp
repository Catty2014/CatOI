#include <cstdio>
#include <cstring>
typedef long long ll;
const int M=30013;
const int N=3;

class Matrix
{
public:
    int n;
    ll a[4][4];
    Matrix (int num)
    {
        memset(a,0,sizeof(a));
        n=num;
    }
    friend Matrix operator * (Matrix A,Matrix B);
    friend Matrix operator ^ (Matrix a,ll p);
};
Matrix A(3),B(3);

Matrix operator * (Matrix A,Matrix B)
{
    Matrix C(3);
    for(int i=1;i<=A.n;i++)
    {
        for(int k=1;k<=A.n;k++)
        {
            for(int j=1;j<=A.n;j++)
            {
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%M)%M;
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

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    ll a,b,n;
    scanf("%lld %lld %lld",&a,&b,&n);
    A.a[1][1]=A.a[1][2]=B.a[1][2]=1;
    B.a[1][1]=a;
    B.a[2][1]=b;
    B=B^(n-2);
    A=A*B;
    printf("%lld\n",A.a[1][1]);
    return 0;
}
