#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>

const int N=1233;
int a[N];
int mp[N];
int n;
int c[N];
int e[N][N];
int valid=1;

void dfs(int pp,int cc,int nn)
{
    c[pp]=cc;
    for(int i=1;i<=n;i++)
    {
        if(e[pp][i])
        {
            if(c[i]==cc)
            {
                valid=0;
                return;
            }
            else if (!c[i])
            {
                dfs(i,3-cc,nn);
            }
        }
        if(e[i][pp])
        {
            if(c[i]==cc)
            {
                valid=0;
                return;
            }
            else if (!c[i])
            {
                dfs(i,3-cc,nn);
            }
        }
    }
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
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n-1) mp[i]=a[i];
        else
        {
            mp[i]=std::min(a[i],mp[i+1]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]<a[j] && mp[j]<a[i])
            {
                e[i][j]=e[j][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!c[i]) dfs(i,1,n);
    }
    std::stack <int> sa,sb;
    std::queue <int> op;
    if(valid)
    {
        int ansn=1;
        int p=0;
        while(ansn<=n)
        {
            if(c[p]==1)
            {
                op.push('a');
                sa.push(a[p++]);
            }
            while(!sa.empty() && sa.top()==ansn)
            {
                sa.pop();
                op.push('b');
                ansn++;
            }
            if(c[p]==1&&(sa.empty()||sa.top()>a[p])) continue;
            while(!sb.empty() && sb.top()==ansn)
            {
                sb.pop();
                op.push('d');
                ansn++;
            }
            if(c[p]==2)
            {
                op.push('c');
                sb.push(a[p++]);
            }
        }
        for(int i=1;i<=2*n;i++)
        {
            char c=op.front();
            op.pop();
            printf("%c ",c);
        }
    }
    else
    {
        printf("0");
    }
    printf("\n");
    return 0;
}
