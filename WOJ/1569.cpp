#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

typedef double db;
typedef long long ll;

const int N=233;
const int M=66666;
const int I=0x73333333;

db d[N][N],f[N],t[N];
int a[N],v[N],nx[N],h[N],x[N],y[N];
int n,tt,s;
db ans=I;

void edgAdd(int x,int y)
{
    v[++tt]=y,nx[tt]=h[x],h[x]=tt;
}

db calc(int i,int j)
{
    return std::sqrt((ll)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int x)
{
    a[x]=s;
    t[s]=std::max(t[s],f[x]);
    for(int i=h[x];i;i=nx[i])
    {
        if(!a[v[i]]) dfs(v[i]);
    }
}

bool cmp(db x,db y)
{
    return x>y;
}

db mxn(db a,db b,db c)
{
    db x[3];
    x[0]=a;
    x[1]=b;
    x[2]=c;
    std::sort(x,x+3,cmp);
    return x[0];
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j]=I;
        }
    }
    for(int i=1;i<=n;i++)
    {
        d[i][i]=0;
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s);
        for(unsigned int j=0;j<strlen(s);j++)
        {
            if(s[j]=='1') d[i][j]=calc(i,j),edgAdd(i,j);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]!=I) f[i]=std::max(d[i][j],f[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i]) s++,dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]!=a[j]) ans=std::min(ans,mxn(t[a[i]],t[a[j]],f[i]+f[j]+calc(i,j)));
        }
    }
    printf("%.6lf\n",ans);
    return 0;
}

