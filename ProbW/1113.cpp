//Single stack

#include<cstdio>
#include<algorithm>

int n;
int rg;
int rt=0;
int a[233333];
int ans=0;

int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        rt=0;
        ans=0;
        rg=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i==1) rg=a[i];
            if(a[i]>=a[i-1]) rt++;
            if(a[i]<a[i-1])
            {
                ans=std::max(ans,rg*rt);
                rg=a[i];
                rt=1;
            }
            // printf("%d %d\n",rg,rt);
        } 
        ans=std::max(ans,rg*rt);
        printf("%d\n",ans);
    }
    return 0;
}