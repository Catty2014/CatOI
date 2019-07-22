#include <bits/stdc++.h> //Code of Pig2014
using namespace std;//Contact me:18111431031@163.com
#define debug(x) printf("var=%d\n",x)//Language:Cpp
typedef long long ll;
const int MOD=1e9+7;
const int N=3;

int n,p;
ll m;
struct Matrix
{
    ll a[5][5];
    int n;
    int m;
    Matrix (int num,int mod)
    {
        memset(a,0,sizeof(a));
        n=num;
        m=mod;
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

int main()
{
    int n,m;
    scanf("%d")
    return 0;
}

