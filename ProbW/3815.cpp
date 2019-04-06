//Hash??!

#include<cstdio>
#include<cstring>

using namespace std;

typedef long long LL;

const int N=2000005;
const int MOD=23333333;

int n,pow[N],hash[N];
char s[N];

int get(int x,int y)
{
    if (x>y) return 0;
    return (hash[y]-(LL)hash[x-1]*pow[y-x+1]%MOD+MOD)%MOD;
}

int check(int x)
{
    int w1=0,w2=0;
    if (x<=n/2) w1=((LL)get(1,x-1)*pow[n/2-x+1]%MOD+get(x+1,n/2+1))%MOD;
    else w1=get(1,n/2);
    if (x>n/2+1) w2=((LL)get(n/2+1,x-1)*pow[n/2-(x-n/2-1)]%MOD+get(x+1,n))%MOD;
    else w2=get(n/2+2,n);
    if (w1==w2) return w1;
    else return 0;
}

int main()
{
    scanf("%d%s",&n,s+1);
    if (n%2==0)
    {
        puts("NOT POSSIBLE");
        return 0;
    }
    pow[0]=1;
    for (int i=1;i<=n;i++) pow[i]=pow[i-1]*27%MOD;
    for (int i=1;i<=n;i++) hash[i]=(hash[i-1]*27+s[i]-'A'+1)%MOD;
    int ans=0,h=0,w;
    for (int i=1;i<=n;i++)
        if (w=check(i))
        {
            if (!ans) ans=i,h=w;
            else if (w!=h) ans=-1;
        }
    if (!ans) puts("NOT POSSIBLE");
    else if (ans==-1) puts("NOT UNIQUE");
    else
    {
        for (int i=1,l=0;l<n/2;i++)
            if (i!=ans) putchar(s[i]),l++;
    }
    return 0;
}