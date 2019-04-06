///It's too violence...

#include <cstdio>
#include <algorithm>

int a[53333];
int b[53333];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    #endif
    int m,n;
    scanf("%d %d",&n,&m);
    int _mx=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(_mx<a[i]) _mx=a[i];
    }
   
    int _max=-1;
    for(int i=1;i<=_mx;i++)
    {
        for(int j=1;j<=_mx;j++)
        {
            //printf("%d %d\n",i,j);
            if(j>=i&&j<=i+m) continue;
            if(j+m>=i&&j<=i) continue;
            int ans=0;
            for(int k=0;k<=m;k++)
            {
                ans+=b[i+k];
                ans+=b[j+k];
            }
            //printf("ans=%d\n",ans);
            if(ans>_max) _max=ans;
        }
    }
    printf("%d\n",_max);
    return 0;
}