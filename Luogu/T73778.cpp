#include <cstdio>

typedef long long ll;

const int N=233;

const int MOD=1e8+7;

ll ksm(ll x,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1) res=res*x%MOD;
        p>>=1;
        x=x*x%MOD;
    }
    return res;
}

int a[N];

int main(void)
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>101) return 1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        ll ansa = 1,num = 0;
        ll ansb=0;
        int l,r;
        scanf("%d %d",&l,&r);
        for(int i=l;i<=r;i++)
        {
            for(int j=i;j<=r;j++)
            {
                ansa=1;
                for(int k=i;k<=j;k++)
                {
                    ansa=ansa*a[k]%MOD;
                }
                ansb+=ansa;
                num++;
            }
        }
        printf("%lld\n",(ansb*ksm(num,MOD-2)%MOD+MOD)%MOD);
    }
    return 0;
}
