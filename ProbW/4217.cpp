#include <bits/stdc++.h> //Code of Pig2014
using namespace std;//Contact me:18111431031@163.com
#define debug(x) printf("var=%d\n",x)//Language:Cpp
typedef long long ll;
const int MOD=1e9+7;
const int maxn=2018;

int n,f,b;
ll s[maxn][maxn];
ll c[maxn][maxn];

void init()//Stirling I
{
    c[0][0]=1;
    s[0][0]=1;
    for(int i=1;i<maxn;i++)
    {
        c[i][0]=c[i][i]=1;
        s[i][0]=0;s[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
            s[i][j]=((i-1)*s[i-1][j]+s[i-1][j-1])%MOD;
        }
    }
}
int main()
{
    int ncase;
    init();
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d %d %d",&n,&f,&b);
        if(f+b-2>n)
        {
            puts("0");
        }
        else
        {
            ll ans=(c[f+b-2][f-1]*s[n-1][b+f-2])%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

