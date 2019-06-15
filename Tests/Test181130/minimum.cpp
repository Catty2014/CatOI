#include <cstdio>
#include <algorithm>
// Shortest Way
const int INF=0x3f3f3f3f;
const int N=100086;
int m,n;

int f[5000][5000];
bool black[N];
// bool walked[5000][5000];
int rd[5000][5000];
int stcount[5000];
int tmp;

inline int read()
{
    char ch;
    int ret=0;
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        ret=ret*10+ch-'0';
        ch=getchar();
    }
    return ret;
}


void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j!=i&&j!=k&&i!=k)
                {
                    f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
}

int main()
{
    // printf("%d",&tmp-&m);
    #ifndef ONLINE_JUDGE
    freopen("minimum.in","r",stdin);
    freopen("minimum.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    if(n>5000)
    {
        printf("impossible\n");
        return 0;
        //No enough size for f[][]!
    }
    for(int i=1;i<=n;i++)
    {
        // black[i]=read();
        scanf("%d ",&black[i]);
    }
    for(int i=1;i<=n;i++)
    {
        // black[i]=read();
        printf("%d ",black[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++)
    {
        // int st=read();
        // int ed=read();
        // f[st][ed]=read();
        int st,ed,w;
        scanf("%d %d %d",&st,&ed,&w);
        // rd[st][stcount[st]++]=ed;
        f[st][ed]=f[ed][st]=w;
    }
    floyd();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(black[i]==1) continue;
        int minanstmp=INF;
        for(int j=1;j<=n;j++)
        {
            
            if(black[j]==0) continue;
            if(minanstmp>f[i][j]) {
                minanstmp=f[i][j];
                
                // walked[i][j]==1;
            }
        }
        if(minanstmp==INF)
        {
            printf("impossible\n");
            return 0;
        }
        ans+=minanstmp;
    }
    printf("%d",ans);
}