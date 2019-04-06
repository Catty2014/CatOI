#include <bits/stdc++.h>
using namespace std;

int a[233];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int targ=n*n;
    if(n%2==1)
    {
        a[n/2+1]=targ;
        for(int i=n/2;i>=1;i--)
        {
            a[i]=a[i+1]-2;
        }
        for(int i=n/2+2;i<=n;i++)
        {
            a[i]=a[i-1]+2;
        }
    }
    else{
        a[n/2+1]=targ+1;
        for(int i=n/2;i>=1;i--)
        {
            a[i]=a[i+1]-2;
        }
        for(int i=n/2+2;i<=n;i++)
        {
            a[i]=a[i-1]+2;
        }
    }
    printf("%d^3=",n);
    for(int i=1;i<n;i++)
    {
        printf("%d+",a[i]);
    }
    printf("%d=%d\n",a[n],n*n*n);
    return 0;
}