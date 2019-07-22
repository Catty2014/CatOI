/****************************************
 * STD:W1564 广场铺砖
 * State Compressed DP
 ****************************************/

#include <cstdio>

int x,y;
int st;//Statement Storaging

long long f[13][(1<<13)];

#define SWP(a,b) {int tmp=a;a=b,b=tmp;}

void dfs(int i,int s1,int s2,int d)//i:line,s1:statenow,s2:ststenext,d:depth
{
    if(d==x) //A square
    {
        f[i+1][s2]+=f[i][s1];
    }
    else
    {
        if( (s1&(1<<d))==0 )
        {
            dfs(i,s1,(s2|(1<<(d))),d+1);
            if(d<x-1 && (s1&(1<<(d+1)))==0 )
            {
                dfs(i,s1,s2,d+2);
            }
        }
        else
        {
            dfs(i,s1,s2&~(1<<d),d+1);
        }
    }
}

int main()
{
    scanf("%d %d",&x,&y);
    if(x*y&1) //x*y%2==1
    {
        printf("-1\n");
        return 0;
    }
    if(x>y) SWP(x,y);
    // printf("x,y=%d %d\n",x,y);
    st=(1<<x)-1;
    f[1][0]=1;
    dfs(1,0,0,0);
    for(int i=2;i<=y;i++)
    {
        for(int j=0;j<=st;j++)
        {
            if(f[i][j])
            {
                dfs(i,j,0,0);
            }
        }
    }
    printf("%lld\n",f[y+1][0]);
    return 0;
}