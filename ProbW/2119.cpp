#include <bits/stdc++.h>
using namespace std;

int a[1333][1333]={},vst[1333]={},n,m,s=0;

void dfs(int x)
{
    vst[x]=1;
    for(int i=1;i<=n;i++)
    {
        if((a[x][i]==1)&&(vst[i]==0)) dfs(i);
    }
}
int main()
{
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vst[i]==0)
        {
            dfs(i);s++;
        }
    }
    printf("%d\n",s);
    return 0;
}

