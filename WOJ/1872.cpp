#include <cstdio>

const int N=13333;
int a[N];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int s,m;
    scanf("%d %d",&s,&m);
    for(int i=0;i<=s;i++)
    {
        a[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        for(int j=l;j<=r;j++)
        {
            a[j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<=s;i++)
    {
        ans+=a[i];
    }
    printf("%d\n",ans);
    return 0;
}
