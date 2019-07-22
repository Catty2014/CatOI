#include <cstdio>
#include <cstring>
#include <queue>

#define C(i) (i-'0')

const int N=33333;
int a[N][2];
int p[N];
int si=1;
char s[N];
int vi[N];
int nx[N];
int ln[N];
std::queue <int> q;

void ins()
{
    int l=strlen(s),nw=1;
    for(int i=0;i<l;i++)
    {
        int t=C(s[i]);
        if(!a[nw][t]) a[nw][t]=++si;
        nw=a[nw][t];
    }
    nx[nw]=1;
}

void build()//???
{
    q.push(1);
    p[1]=0;
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
        for(int i=0;i<=1;i++)
        {
            if(!a[nw][i])
            {
                a[nw][i]=a[p[nw]][i];
                continue;
            }
            int k=p[nw];
            while(!a[k][i]) k=p[k];
            p[a[nw][i]]=a[k][i];
            nx[a[nw][i]]|=nx[p[a[nw][i]]];
            q.push(a[nw][i]);
        }
    }
}

bool dfs(int x)
{
    ln[x]=1;
    for(int i=0;i<=1;i++)
    {
        if(ln[a[x][i]]) return 1;
        if(vi[a[x][i]]||nx[a[x][i]]) continue;
        vi[a[x][i]]=1;
        if(dfs(a[x][i])) return 1;
    }
    ln[x]=0;
    return 0;
}

int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<=1;i++)
    {
        a[0][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        ins();
    }
    build();
    if(dfs(1)) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}
