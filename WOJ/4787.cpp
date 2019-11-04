#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MAXN 1000000
using namespace std;
template<typename T>void Read(T &cn)
{
    char c;int sig = 1;
    while(!isdigit(c = getchar()))if(c == '-')sig = -1; cn = c-48;
    while(isdigit(c = getchar()))cn = cn*10+c-48; cn*=sig;
}
template<typename T>void Write(T cn)
{
    if(cn < 0) {putchar('-'); cn = 0-cn; }
    int wei = 0; T cm = 0; int cx = cn%10; cn/=10;
    while(cn)cm = cm*10+cn%10,cn/=10,wei++;
    while(wei--)putchar(cm%10+48),cm/=10;
    putchar(cx+48);
}
struct qwe{
    int a,b,ne;
};
struct qwer{
    int a,b;
    inline friend bool operator <(qwer a,qwer b) {return a.a < b.a; }
    void mk(int cn,int cm) {a = cn; b = cm; }
};
qwe a[MAXN*2+1];
int alen;
int head[MAXN+1];
int n,ro;
int fa[MAXN+1],f[MAXN+1],zhi[MAXN+1];
qwer lie[MAXN+1];
int ans[MAXN+1];
int ge[MAXN+1][24];
void lian(int cn,int cm)
{
    a[++alen].a = cn;
    a[alen].b = cm;
    a[alen].ne = head[cn];
    head[cn] = alen;
}
void dfs(int cn)
{
    f[cn] = zhi[cn];
    for(int i = head[cn];i;i = a[i].ne)
    {
        int y = a[i].b;
        if(y == fa[cn])continue;
        fa[y] = cn;
        dfs(y);
        f[cn] = f[cn] + f[y];
    }
}
void set_ge(int cn,int cm)
{
    for(int i = 0;i<=cm;i++)ge[cn][i] = 0;
    for(int i = head[cn];i;i = a[i].ne)
    {
        int y = a[i].b;
        if(y == fa[cn])continue;
        set_ge(y,cm);
        for(int j = 0;j<=cm;j++)ge[cn][j] = ge[cn][j] + ge[y][j] + ((f[y]&(1<<j)) != 0);
    }
}
int erwei(int cn) {int guo = 0; while(cn)guo++,cn >>= 1; return guo; }
void zuo(int cn)
{
    int he = 0,lei = 0; lie[0].a = lie[1].a-1;
    for(int i = 1;i<=n;i++)
    {
        if(lie[i-1].a != lie[i].a)he += lei,lei = 0;
        ans[lie[i].b] |= (1<<cn)*(he > ge[lie[i].b][cn]);
        lei += ((f[lie[i].b] & (1<<cn)) != 0);
    }
}

int is_a_chain=0;
int deg[MAXN];
signed main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    Read(n); Read(ro);
    alen = 0; memset(head,0,sizeof(head));
    for(int i = 1;i<n;i++)
    {
        int bx,by; Read(bx); Read(by);
        lian(bx,by); lian(by,bx);
        deg[bx]++;
        deg[by]++;
    }
    int ta=0,tb=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1) ta++;
        if(deg[i]==2) tb++;
    }
    if(ta==2&&ta+tb==n)   is_a_chain=1;
    if(is_a_chain)
    {
        for(int i=1;i<=n;i++)
        {
            printf("0 ");
        }
        return 0;
    }
    for(int i = 1;i<=n;i++)Read(zhi[i]);
    fa[ro] = 0;
    dfs(ro);
    for(int i = 1;i<=n;i++)lie[i].mk(f[i],i);
    sort(lie+1,lie+n+1);
    for(int i = 1;i<=n;i++)ans[i] = 0; int lin = erwei(f[ro]);
    set_ge(ro,lin);
    for(int i = 0;i<=lin;i++)zuo(i);
    for(int i = 1;i<=n;i++)Write(ans[i]),putchar(' '); putchar('\n');
    return 0;
}

