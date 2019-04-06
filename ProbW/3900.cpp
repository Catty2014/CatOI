#include <cstdio>
#include <iostream>
using std::cin;
typedef long long ll;

int n;
ll a,b,lcm,ans,k,d,x,y;

int exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    ll ret=exgcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
    return ret;
}

int main()
{
    while(cin>>n)
    {
        
        scanf("%lld %lld",&a,&b);
        lcm=a;ans=b;
        bool noanswer=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b);
            b=(b-ans%a+a)%a;
            d=exgcd(lcm,a,x,y);
            if(b%d)
            {
                noanswer=1;
            }
            k=x*(b/d)%a;
            ans+=k*lcm;
            lcm=lcm/d*a;
            ans=(ans%lcm+lcm)%lcm;
        }
        if(noanswer==1) 
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n",ans);
    }
    return 0;
}