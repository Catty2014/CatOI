/****************************************
 * W3010 骰子
 * 概率
 ****************************************/

#include <cstdio>
#include <algorithm>

int b[166];

void dfs(int t,int v)
{
    // printf("t=%d v=%d\n",t,v);
    if(t<=0) {b[v]+=1;return;}
    for(int i=1;i<=6;i++)
    {
        dfs(t-1,v+i);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if(m<n) {printf("1\n");return 0;}
    if(m>144) {printf("0\n");return 0;}
    int a=1;
    for(int i=1;i<=n;i++)
    {
        a*=6;
        if(a>2147483647) return 1;
    }
    // printf("%d\n",a);
    dfs(n,0);
    int l=0;
    for(int i=m;i<=147;i++)
    {
        l+=b[i];
    }
    int k=std::__gcd(a,l);
    if(l==a&&l!=0) {printf("1\n");return 0;}
    if(l==0) {printf("0\n");return 0;}
    printf("%d/%d",l/k,a/k);
    return 0;
}