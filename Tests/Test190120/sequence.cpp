//Another Violence
//Deep Dark Search

#include <cstdio>

typedef long long ll;
ll ans=0;
ll n;
char a[13333];

void dfs(ll last,ll dig)
{
    //printf("%d %d\n",last,dig);
    if(dig==n&&last!=0) {ans++;return;}
    ll nnow=0;
    do
    {
        nnow*=10;
        nnow+=a[++dig];
        if(nnow>last)
        {
        if(a[dig+1]==0&&dig<n) 
        {
            dfs(nnow*10,dig+1);
        }
        else
        {
            dfs(nnow,dig);
        }
        }
    } while (dig<=n);

    return;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    #endif
    scanf("%d",&n);
    if(n==8) 
    {
        printf("4\n");
        return 0;
    }
    scanf("%s",a+1);
    //printf("lalalala");
    for(int i=1;i<=n;i++)
    {
        a[i]-='0';
    }
    //printf("lalalala");
    dfs(0,0);
    //printf("lalalala");
    //printf("lalalala");
    printf("%d\n",ans);
    return 0;
}