#include <cstdio>
typedef long long ll;

#define max(a,b) ((a>b)?a:b)
const ll N=555;

ll m,n;
ll ans=0;
ll s[N][N];
ll a[N][N];

ll V(ll lx,ll ly,ll rx,ll ry)
{
    return s[rx][ry]+s[lx-1][ly-1]-s[rx][ly-1]-s[lx-1][ry];
}

ll S(ll lx,ll ly,ll rx,ll ry)
{
    return (rx-lx+1)*(ry-ly+1);
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    }
    /* for(ll i=1;i<=n;i++) */
    /* { */
    /*     for(ll j=1;j<=m;j++) */
    /*     { */
    /*         prllf("%d ",s[i][j]); */
    /*     } */
    /*     putchar('\n'); */
    /* } */
    for(ll lx=1;lx<=n;lx++)
    {
        for(ll ly=1;ly<=m;ly++)
        {
            for(ll rx=lx+1;rx<=n;rx++)
            {
                for(ll ry=ly+1;ry<=m;ry++)
                {
                    if(V(lx,ly,rx,ry)>=0)
                    {
                        ans=max(ans,S(lx,ly,rx,ry));    //Violence Ex
                        /* prllf("ANS:%d POS:%d %d %d %d\n",S(lx,ly,rx,ry),lx,rx,ly,ry); */
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
