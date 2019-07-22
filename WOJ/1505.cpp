/****************************************
 *   W1505 美丽数
 * ->W1179 女仆酱的求助
 ****************************************
 * DigitDP
 * 思路都差不多
 * 1505不管0,1179排除0
 ****************************************/
#include <cstdio>
#include <cstring>

typedef long long ll;

ll d[20][2550][50];
int id[2550];
int dig[20];

const int MOD=2520;//1~10的最小公倍数
//妙啊

int gcd(int a,int b)
{
    return (b==0)?(a):gcd(b,a%b);
}
// #define LCM(a,b) (a/(gcd(a,b))*b)    //<--这个东西的锅?

int LCM(int a,int b)
{
    return a/gcd(a,b)*b;
}

void init()
{
    int n=0;
    for(int i=1;i<=MOD;i++)
    {
        if(MOD%i==0)
        {
            id[i]=n++;
        }
    }
    memset(d,-1,sizeof(d));
}

ll dfs(int p,int sum,int lcm,bool lim)
{
    if(p==-1) //仅有一个数字
    {
        return (sum%lcm==0);
    }
    if( (!lim) && (d[p][sum][id[lcm]]!=-1) )
    {
        return d[p][sum][id[lcm]];
    }
    ll ans=0;
    int end=lim?dig[p]:9;//常见操作：取上界
    for(int i=0;i<=end;i++)
    {
        int nsum=(sum*10+i)%MOD;//当前数字(舍弃大于2520的部分)
        int nlcm=lcm;//最小公倍数
        if(i)
        {
            nlcm=LCM(nlcm,i);
        }
        ans+=dfs(p-1,nsum,nlcm,(lim&&(i==end)));
    }
    if(!lim)
    {
        d[p][sum][id[lcm]]=ans;
    }
    return ans;
}

ll sol(ll x)//取每一位最大值，并dfs
{
    int p=0;
    while(x)
    {
        dig[p++]=x%10;
        x/=10;
    }
    return dfs(p-1,0,1,1);
}


int main()//for:1179
{
    init();
    int T;
    scanf("%d",&T);
    for(;T--;)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",sol(b)-sol(a-1));
    }
    return 0;
}

/*
int main()//for:1505
{
    init();
    ll a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        printf("%lld\n",sol(b)-sol(a-1));
    }
    return 0;
}
*/