/****************************************
 * WOJ1900
 * H2O
 ****************************************/
#include <cstdio>

int a[233];
int l;
bool d;
int ans=1;

void ansl(int x)
{
    for(int i=x-1;i>0;i--)
    {
        if(a[i]>0) ans++;
    }
}

void ansr(int x)
{
    for(int i=x+1;i<=100;i++)
    {
        if(a[i]<0) ans++;
    }

}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t<0) a[-t]=-1;
        else a[t]=1;
        if(i==1) l=t;
    }
    if (l<0) 
    {
        l=-l;
        d=1;
    }
    for(int i=l+1-2*d;i>0&&i<=100;i+=1-2*(d))
    {
        if(d==0)
        {
            if(a[i]==-1)
            {
                ansl(l);
                ansr(l);
                break;
            }
        }
        else
        {
            if(a[i]==1)
            {
                ansl(l);
                ansr(l);
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
