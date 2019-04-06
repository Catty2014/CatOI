/****************************************
 * STD:W1565 硬木地板
 * SCDP
 ****************************************/

#include <cstdio>

#define swap(a,b) {int tmp=a;a=b;b=tmp;}
#define n_l(i) (1<<i)
#define n_0(a,i) (!(a&n_l(i)))
#define n_a(a,i) (a|n_l(i))
// #define n_r(a,i) (a&~(n_l(i))
typedef long long ll;

const int N=13;
const int M=n_l(13);

ll f[N][M];
int x,y,st;

void dfs(int i,int sp,int sn,int d) //i:Line,sp:state_now,sn:state_next
{
    if(d==x)
    {
        f[i+1][sn]+=f[i][sp];
        return ;
    }
    if(n_0(sp,d))
    {
        int t=0;
        if(n_0(sn,d))
        {
            t=1;
            dfs(i,sp,n_a(sn,d),d+1);
            if(d<x-1 && n_0(sn,d+1))
            {
                dfs(i,sp,n_a(n_a(sn,d),d+1),d+1);
            }
            if(d>0 && n_0(sn,d-1))
            {
                dfs(i,sp,n_a(n_a(sn,d),d-1),d+1);
            }
        }
        if(d<x-1 && n_0(sp,d+1))
        {
            t=1;
            dfs(i,sp,sn,d+2);
            if(n_0(sn,d+1))
            {
                dfs(i,sp,n_a(sn,d+1),d+2);
            }
            if(n_0(sn,d))
            {
                dfs(i,sp,n_a(sn,d),d+2);
            }
        }
        if(t==0) return ;
    }
    else
    {
        dfs(i,sp,sn,d+1);
    }
}



int main()
{
    scanf("%d %d",&x,&y);
    if(x*y&1)
    {
        printf("0\n");
        return 0;
    }
    if(x>y) swap(x,y);
    st=n_l(x)-1;
    f[1][0]=1;
    dfs(1,0,0,0);
    for(int i=2;i<=y;i++)
    {
        for(int j=0;j<=st;j++)
        {
            if(f[i][j])
            {
                dfs(i,j,0,0);
                // printf("%lld\n",f[y+1][0]);
            }
        }
    }
    printf("%lld\n",f[y+1][0]);
    return 0;
}