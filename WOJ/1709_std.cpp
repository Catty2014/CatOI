#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack> 
#include <ctime>

using namespace std;

long long X1,X2,Y1,Y2;
long long k1,k2;
bool fs;

long long gcd(long long a,long long b)
{
    long long r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

long long abs_(long long x)
{
    if(x>0)return x;else return -x;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.ans","w",stdout);
#endif
    while(cin>>X1>>Y1>>X2>>Y2)
    {
        if(X1==X2||Y1==Y2)
        {
            printf("Error\n");
            continue;
        }
        if(X1!=0)
        {
            swap(X1,X2);
            swap(Y1,Y2);
        }
        k1=Y1;  k2=X2;
        if((k1<0&&k2<0)||(k1>0&&k2>0))fs=1;else fs=0;
        k1=abs_(k1); k2=abs_(k2);
        long long ggg=gcd(k1,k2);
        k1/=ggg; k2/=ggg;
        printf("y=");
        if(fs)printf("-");
        if((k1==1&&k2!=1)||(k1!=1))cout<<k1;
        if(k2!=1)cout<<"/"<<k2;
        printf("x");
        if(Y1==0)printf("\n");
        else 
            if(Y1<0)cout<<Y1<<"\n";else cout<<"+"<<Y1<<"\n";
    }
    return 0;
}
