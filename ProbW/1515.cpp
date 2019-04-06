#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;
int ans=0;

int L,R;
void dfs(int last,int num)
{
    /* printf("%d\n",num); */
    if(num>R) return;
    if(num>=L) ans++;
    for(int i=0;i<=9;i++)
    {
        if(i==4) continue;
        if(last==6&&i==2) continue;
        dfs(i,num*10+i);
    }
}
int main()
{
    scanf("%d %d",&L,&R);
    for(int i=1;i<=9;i++)
    {
        if(i==4) continue;
        dfs(i,i);
    }
    printf("%d\n",ans);
    return 0;
}

