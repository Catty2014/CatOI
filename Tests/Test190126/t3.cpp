//H2O?!

#include <cstdio>

const int MOD=1e9+7;

unsigned int fsmod(int n)//fsmod2
{
    unsigned int ans=1;int t=2;
    while(n)
    {
        
        if(n&1) ans=(ans*t)%MOD;
        n>>=1;
        t=t*2%MOD;
    }   
    // printf("ans=%d\n",ans);
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t3.in","r",stdin);
        freopen("t3.out","w",stdout);
    #endif
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    printf("%d\n",(fsmod(m-k+1)-1)*n%MOD);
}