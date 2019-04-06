#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tg;
    int mind=0x7fffffff;
    int ans=-1;
    scanf("%d %d",&n,&tg);
    for(int i=1;i<=n;i++)
    {
        /* int id,dist; */
        /* scanf("%d %d",&id,&dist); */
        /* if(dist<=mind&&id<=tg) */ 
        /* { */
        /*     ans=dist; */
        /*     mind=dist; */
        /* } */
        int a,b;
        scanf("%d %d",&a,&b);
        if(b<=tg&&a<mind)
        {
            mind=a;
            ans=a;
        }
    }
    if(ans==-1)
    {
        printf("TLE");
        return 0;
    }
    printf("%d",ans);
    return 0;
}

