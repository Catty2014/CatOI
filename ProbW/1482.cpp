//WOJ #1482 字符序列

#include <bits/stdc++.h>
using namespace std;

int ans=0;
int a[20];
int tgd=0;

void dfs(int dig)
{
    for(int i=1;i<=3;i++)
    {
        
        //if (dig>=2) printf("%d %d %d %d %d",dig,i,a[dig-1],a[dig-2],a[dig-3]);
        if(dig>=3&&i==a[dig-1]&&a[dig]==a[dig-2]) continue;
        /* for(int i=1;i<=dig;i++)
        {
            printf("%d",a[i]);
        } */
        //printf("\n");
        a[++dig]=i;
        if(dig>tgd) {
            ans++;
            return;
        }
        else dfs(dig);
        a[dig--]=0;
    }
}

int main()
{
    scanf("%d",&tgd);
    dfs(0);
    printf("%d\n",ans);
    return 0;
}