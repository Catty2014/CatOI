#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;
bool a[1000033];

int main()
{
    int n;
    scanf("%d",&n);
    int max_r=0;
    int max_l=1333333;
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        if(l>r)swap(l,r);
        for(int j=l;j<=r;j++)
        {
            a[j]=1;
        }
        max_r=r>max_r?r:max_r;
        max_l=l<max_l?l:max_l;
    }
    int max_n=0,max_u=0;
    int tg_n=0,tg_u=0;
    for(int i=max_l;i<=max_r+1;i++)
    {
        if(a[i]==0)
        {
            tg_n++;
            max_u=max_u>(tg_u-1)?max_u:(tg_u-1);
            tg_u=0;
        }
        if(a[i]!=0)
        {
            tg_u++;
            max_n=max_n>(tg_n+1)?max_n:(tg_n+1);
            tg_n=0;
        }
    }
    if(a[max_r]==0||max_n==1) max_n--;
    printf("%d %d\n",max_u,max_n);
    return 0;
}

