
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N=333333;

int n;
int a[N],b[N];
int cons=0;
typedef double db;
struct Number
{
    db v;
    int p;
}s[N];

int cmp(const Number&a,const Number&b)
{
    return a.v<b.v;
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
        scanf("%d %d",&a[i],&b[i]);
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        double p=a[i],q=b[i];
        s[i].v=(double)(-q)/(p);
        s[i].p=std::abs(a[i]);
        c+=std::abs(a[i]);
        cons+=abs(b[i]);
    }
    if(c==0)
    {
        double tmp=cons;
        printf("%lf\n",tmp);
        return 0;
    }
    if(c&1) c++;
    c/=2;
    db v=0.00;
    std::sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        c-=s[i].p;
        if(c<=0)
        {
            v=s[i].v;
            break;
        }
    }
    db ans=0.00;
    for(int i=1;i<=n;i++)
    {
        double p=a[i],q=b[i];
        ans+=std::fabs(p*v+q);
    }
    printf("%lf\n",ans);
    return 0;
}
