//SDOJ #1316 ÌØÊâÖÊÊý
//C

#include <cstdio>

bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(0==x%i)
        return false;
    }
    return true;
} 

int n;

void spm(int sum,int cur)
{
    if(cur==n) printf("%d\n",sum);
    for(int i=1; i<=9; i++)
    {
        if(i%2==0) continue;
        int asum= sum*10+i;
        if(prime(asum)) 
        {
            spm(asum,cur+1);
        }  
    }
}

int main()
{
    scanf("%d",&n);
        spm(2,1);
        spm(3,1);
        spm(5,1);
        spm(7,1);
    return 0;
}

