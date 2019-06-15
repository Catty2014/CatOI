//The First!!!

#include <cstdio>

typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
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
    while(1)
    {
        ll a,b,c,k;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
        if(a==0&&b==0&&c==0&&k==0) return 0;
        k=(ll)1<<k;
        ll x=0,y=0;
        ll ret=exgcd(c,k,x,y);
        if((b-a)%ret!=0)
        {
            printf("FOREVER\n");
            continue;
        }
        ll sum=(x*(b-a)/ret)%k;
        sum=(sum%(k/ret)+k/ret)%(k/ret);
        printf("%lld\n",sum);
    }
}

//a+c*x=b(mod 2^k) ->  c*x+2^k*y=b-a
