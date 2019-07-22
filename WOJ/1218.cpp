/****************************************
 * W1218 Odd-Even Number
 * DigitDP
 * Using Memorized DFS
 ****************************************/

#include <cstdio>
#include <cstring>

#define _ri register int
typedef long long ll;
int dig[23];
int dn=0;
ll d[21][11][11];

ll dfs(int p,int j,int k,int _0,int lim)
{
    // printf("Intro\n");
    if(p==0)
    {
        if(j==k) return 0;
        else return 1;
    }
    if((!lim)&&(!_0)&&d[p][j][k]!=-1) return d[p][j][k];
    int maxn=(lim)?(dig[p]):(9);
    ll ans=0;
    for(int i=0;i<=maxn;i++)
    {
        if(_0)
        {
            ans+=dfs(p-1,(i%2==1),1,(_0&&(i==0)),(lim&&(i==maxn)));
        }
        else
        {
            if(j==i%2)
            {
                ans+=dfs(p-1,j,((k+1)%2==1),(_0&&(i==0)),(lim&&(i==maxn)));
            }
            else if (k!=j)
            {
                ans+=dfs(p-1,j^1,1,(_0&&(i==0)),(lim&&(i==maxn)));
            }
        }
    }
    if(!_0&&!lim) d[p][j][k]=ans;
    return ans;
}

ll sol(ll a)
{
    dn=0;
    while(a)
    {
    // printf("Intro\n");
        dig[++dn]=a%10;
        a/=10;
    }
    // printf("DN==%d\n",dn);
    return dfs(dn,0,1,1,1);
}

int main()
{
    memset(d,-1,sizeof(d));
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        ll a=0,b=0;
        scanf("%lld %lld",&a,&b);
        printf("Case #%d: %lld\n",i,sol(b)-sol(a-1));
    }
    return 0;
}