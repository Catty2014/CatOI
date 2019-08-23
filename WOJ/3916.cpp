#include <cstdio>
#include <algorithm>
#include <cstring>

const int N=2333;

class xint
{
public:
    int l;
    int a[2333];
    void clr()
    {
        l=0;
        memset(a,0,sizeof(a));
    }
    friend xint operator * (const xint &a,const xint &b);
    xint fMod(int a,int b)
    {
        xint p;
        xint t;
        t.clr();
        p.clr();
        t.l=t.a[1]=1;
        while(a)
        {
            p.l++;
            p.a[p.l]=a%10;
            a/=10;
        }
        while(b)
        {
            if(b&1) t=t*p;
            b>>=1;
            p=p*p;
        }
        return t;
    }
}x;

int n;
int t,no[N],m[N],s[N],a[N];

xint operator * (const xint &a,const xint &b)
{
    xint s;
    s.clr();
    int n=a.l+b.l;
    int ln=std::max(a.l,b.l);
    for(int i=1;i<=ln;i++)
    {
        int x=0;
        for(int j=1;j<=ln;j++)
        {
            s.a[i+j-1]+=a.a[i]*b.a[j]+x;
            x=s.a[i+j-1]/10;
            s.a[i+j-1]%=10;
        }
        s.a[ln+i]=x;
    }
    while(s.a[n]==0) n--;
    s.l=n;
    return s;
}

void clr()
{
    memset(no,0,sizeof(no));
    for(int i=2;i<=N;i++)
    {
        if(!no[i]) s[++t]=i,m[i]=t;
        for(int j=1;j<=t&&s[j]*i<=N;j++)
        {
            no[s[j]*i]=1;
            if(i%s[j]==0) break;
        }
    }
}

void calc(int x,int v)
{
    for(int i=1;i<=t&&s[i]*s[i]<=x;i++)
    {
        if(x%s[i]==0)
        {
            while(x%s[i]==0)
            {
                a[i]+=v;
                x/=s[i];
            }
        }
    }
    if(x>1) a[m[x]]+=v;
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    xint ans;
    scanf("%d",&n);
    clr();
    for(int i=n+1;i<=n*2;i++) calc(i,1);
    for(int i=1;i<=n+1;i++) calc(i,-1);
    ans.clr();
    ans.l=ans.a[1]=1;
    for(int i=1;i<=t;i++)
    {
        ans=ans*x.fMod(s[i],a[i]);
    }
    for(int i=ans.l;i>=1;i--)
    {
        printf("%d",ans.a[i]);
    }
    return 0;
}
