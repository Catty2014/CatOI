#include <cstdio>

typedef long long ll;

const int N=666;
const int M=17680321;

ll n,a,b[4],in[N],f[N][N][2];

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int t=0;
    scanf("%lld",&n);
    in[1]=1;
    for(int i=2;i<=n;i++)
    {
        in[i]=(ll)((ll)(M-M/i)*(ll)in[M%i])%M;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        b[a]++;
    }
    f[0][0][0]=0;
    for(int k=0;k<=n;k++)
    {
        for(int j=0;j+k<=n;j++)
        {
            for(int i=0;i+j+k<=n;i++)
            {
                if(i||j||k)
                {
                    f[i][j][t]=(ll)(n*in[i+j+k])%M;
                    f[i][j][t]=(ll)(f[i][j][t]+(ll)((ll)(f[i-1][j][t]*i)%M*in[i+j+k]))%M;
                    f[i][j][t]=(ll)(f[i][j][t]+(ll)((ll)(f[i+1][j-1][t]*j)%M*in[i+j+k]))%M;
                    f[i][j][t]=(ll)(f[i][j][t]+(ll)((ll)(f[i][j+1][t^1]*k)%M*in[i+j+k]))%M;
                    if(i==b[1]&&j==b[2]&&k==b[3]) 
                    {
                        printf("%lld\n",f[i][j][t]);
                        return 0;
                    }
                }
            }
            t^=1;
        }
    }
}

// (ll)
