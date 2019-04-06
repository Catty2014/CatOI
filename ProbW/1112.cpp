#include <cstdio>
#include <algorithm>

const int INF=1e9+7;
int n,best,m;
int mV[33],mS[33],mxV[33];

void dfs(int i,int v,int h,int r,int s)
{
    if(i==0)
    {
        if(v==n&&s<best) best=s;
        return ;
    }
    if(v+mV[i-1]>n) return; //可行：总体积
    if(s+mS[i-1]>best) return ; //最优：最小表面积
    if(s+2*(n-v)/r>=best) return ;//最优：预计最小表面积
    //DFS Core
    for(int j=r-1;j>=i;j--)//大->小
    {
        if(i==m) s=j*j;
        int mh=std::min(h-1,(n-v-mV[i-1])/(j*j));
        for(int k=mh;k>=i;k--)
        {
            dfs( i-1 , v+j*j*k , k , j , s+2*j*k );
        }
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=20;i++)
    {
        mV[i]=mV[i-1]+i*i*i;//v=i^3
        mS[i]=mS[i-1]+2*i*i;//s=i^2;
    }
    best=INF;
    dfs(m,0,n+1,n+1,0);
    if(best==INF)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n",best);
    return 0;

}