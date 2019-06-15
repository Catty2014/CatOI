#include <cstdio>
#include <iostream>

int a[13333],b[13333];
long double asum,bsum;

int n;

int gcd(int x,int y)
{
    int t;
    while(y)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return  x;
}

int main()
{  
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        if(i==1)
        {
            asum=p;bsum=q;
            p=q=1;
        }
        if(p!=0&&q!=0&&asum!=0&&bsum!=0)
        {
            int _G=gcd(p*asum,q*bsum);
            if(_G!=1)
            {
                asum=asum*p/_G;
                bsum=bsum*q/_G;
            }
            else
            {
                asum=asum*p;bsum=bsum*q;
            }
            
        }
        else
        {
            asum=asum*p;bsum=bsum*q;
        }
        //std::cerr<<asum<<" "<<bsum<<"\n";
        if(asum>bsum)
        {
            printf("A\n");
        }
        if(asum<bsum)
        {
            printf("B\n");
        }
        if(asum==bsum)
        {
            printf("equal\n");
        }
    }
    return 0;
}