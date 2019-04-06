#include <cstdio>

int n;
int a[133333];
int k;
int ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(a[k]<t)
        {
            a[++k]=t;
        }
        else
        {
            while(a[k]>=t)
            {
                k--;
                if(k<0) break;
            }
            a[++k]=t;
        }
        if(k>ans) ans=k;
    }
    if(ans==1) ans=0;
    printf("%d\n",ans);
}