/******************************
 * W1808 积木大赛 
 ******************************/
#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int ls=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int cr=0;
        scanf("%d",&cr);
        if(cr>ls) ans+=cr-ls;
        ls=cr;
    }
    printf("%d\n",ans);
    return 0;
}