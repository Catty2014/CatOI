#include<cstdio>
#include<algorithm>
#define ll long long
int m,n;
long long ans=0;
short p[34];

void dfs(int pos,int k,int s)
{
    if(s>n) return;
    if(pos==m+1)
    {
        if(k&1)
        {
            ans-=n/s;
        }
        else
        {
            ans+=n/s;
        }
        return ;
    }
    dfs(pos+1,k,s);
    dfs(pos+1,k+1,(ll)s*p[pos]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p[i]);
    }
    std::sort(p+1,p+m+1);
    m=std::unique(p+1,p+m+1)-p-1;
    dfs(1,0,(ll)1);
    printf("%lld\n",n-ans);
    return 0;
}