//SDOJ #1316 ÌØÊâÖÊÊı
//C

#include<iostream>
using namespace  std;

int n;

bool IsPrime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(0==x%i)
        return false;
    }
    return true;
} 

void dfs(int sum,int cur)
{
    if(cur==n) cout<<sum<<endl;
    for(int i=1; i<=9; i++)
    {
        if(i%2==0) continue;
        int asum= sum*10+i;
        if(IsPrime(asum)) 
        {
            dfs(asum,cur+1);
        }  
    }
}


int main()
{
    while(cin>>n)
    {
        dfs(2,1);
        dfs(3,1);
        dfs(5,1);
        dfs(7,1);
    }
    return 0;
}
