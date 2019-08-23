#include <cstdio>

int getdig(int n)
{
    int r=0;
    while(n)
    {
        n/=10;
        r++;
    }
    return r;
}

int main()
{
    int k=0;
    long long g=0;
    bool p=0;
    while(scanf("%d",&k)!=-1&&k!=0)
    {
        g=0;
        for(int i=1;i<=getdig(k)+3000;i++)
        {
            g*=10;
            g+=8;
            if(i>=getdig(k) && (g%k==0)) 
            {
                printf("%d\n",i);
                p=1;
                break;
            }
        }
        if(p==0) printf("0\n");
        p=0;
    }
    return 0;
}
