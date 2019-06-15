//DETERMINATION!
#include <bits/stdc++.h> //Code of Pig2014
using namespace std;//Contact me:18111431031@163.com
#define debug(x) printf("var=%d\n",x)//Language:Cpp
typedef long long ll;
const int MOD=1e9+7;

struct  Mercy
{
    int n,m;
    int a[5][5];
    Mercy(int p,int q)
    {
        memset(a,0,sizeof(a));
        n=p,m=q;
    }
    friend Mercy operator * (Mercy A,Mercy B);
    friend Mercy operator ^ (Mercy A,ll p);
};

Mercy operator * (Mercy A,Mercy B)
{
    Mercy C(5,A.m);
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

Mercy operator ^ (Mercy A,ll p)
{
    Mercy C(5,A.m);
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
    scanf("%d %d",&n,&m);
    Mercy A(5,m);
    Mercy B(5,m);
    A.a[1][1]=0;
    A.a[1][2]=1;
    A.a[1][3]=1;
    return 0;
}

