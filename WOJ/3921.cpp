#include <cstdio>

int n,a[23];

int dfs(int x,int s,int t)
{
    if(!s&&t) return 1;
    if(x>n) return 0;
    if(dfs(x+1,s,t)) return 1;
    if(dfs(x+1,s^a[x],t+1)) return 1;
    return 0;

}

int main()
{
    for(int i=1;i<=10;i++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%s\n",dfs(1,0,0)?"NO":"YES");
    }
    return 0;
}
