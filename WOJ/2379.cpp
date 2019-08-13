#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int M=233;

int n,t,s,e;
int cnt,mp[1233];

struct Matrix
{
    int x,m[M][M];
    Matrix() {x=1,memset(m,0x33,sizeof(m));}
}m;

int gid(int x)
{
    return mp[x]?mp[x]:mp[x]=++cnt;
}

Matrix operator * (Matrix a,Matrix b)
{
    Matrix c;
    c.x=a.x;
    for(int i=1;i<=a.x;i++)
    {
        for(int j=1;j<=b.x;j++)
        {
            for(int k=1;k<=a.x;k++)
            {
                c.m[i][j]=min(c.m[i][j],a.m[i][k]+b.m[k][j]);
            }
        }
    }
    return c;
}

Matrix operator ^ (Matrix a,int k)
{
    Matrix c;
    bool flg=1;
    while(k)
    {
        if(k&1)
        {
            if(flg==1)
            {
                c=a;
                flg=0;
            }
            else
            {
                c=c*a;
            }
        }
        a=a*a;
        k>>=1;
    }
    return c;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d %d %d",&n,&t,&s,&e);
    for(int i=1;i<=t;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&z,&x,&y);
        x=gid(x),y=gid(y);
        m.m[x][y]=m.m[y][x]=z;
    }
    s=gid(s);
    e=gid(e);
    m.x=cnt;
    Matrix ans=m^n;
    printf("%d\n",ans.m[s][e]);
    return 0;
}
