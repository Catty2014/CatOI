#include <cstdio>

int fMul(int b,int k,int m)
{
    int r=1;
    while(k)
    {
        if(k&1) r=(r*b)%m;
        b=(b*b)%m;
        k>>=1;
    }
    return r;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int n,m,k,x;
    scanf("%d %d %d %d",&n,&m,&k,&x);
    printf("%d\n",(x+m*fMul(10,k,n))%n);
    return 0x00;
}
