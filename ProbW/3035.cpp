// *你还要再加把劲！

#include <cstdio>

const int N=100233;//Will this make fault?
typedef long long ll;

ll dp[N],s[N]={};
ll f[N];
int k,n,idx[N],t,h;


int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }   
    h=t=0;
    idx[0]=0;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(h<t && idx[h]<i-k) h++;
        dp[i]=f[h]+s[i];
        while(h<=t && f[t]<dp[i-1]-s[i]) t--;
        idx[++t]=i;f[t]=dp[i-1]-s[i];
    }
    printf("%lld\n",dp[n]);
    return 0;
}