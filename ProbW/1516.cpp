/****************************************
 * W1516 Amount of Degrees
 * DigitDP
 * Binary Tree???!!!
 ****************************************/
#include <cstdio>
#include <cstring>
int f[33][33];
int a[33];
int b;

void init()
{   memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int i=1;i<=31;i++)
    {
        f[i][0]=f[i-1][0];
        for(int j=1;j<=i;j++)
        {
            f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
 
}
 
int solve(int x,int k)
{
    int pos=1;
    while(x)
    {
        a[pos++]=x%b;
        x/=b;
    }
    int ans=0;
    for(int i=pos-1;i>=1;i--)
    {
        if(a[i]>1)
        {
            ans+=f[i-1][k]+f[i-1][k-1];
            break;
        }
        else if(a[i]==1)
        {
            ans+=f[i-1][k];
            k--;
        }
        if(k<0)break;
 
    }
   return ans;
}
int main()
{
    int n,m,k;
    init();
    scanf("%d%d%d%d",&n,&m,&k,&b);
    printf("%d\n",solve(m+1,k)-solve(n,k));
    return 0;
}