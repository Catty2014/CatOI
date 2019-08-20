#include <cstdio>

bool Is_prime(int n)
{
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%6!=1&&n%6!=5) return false;
    for( int i=5;i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0) return false;
    return true;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        printf("%s\n",Is_prime(t)?"yes":"no");
    }
    return 0;
}
