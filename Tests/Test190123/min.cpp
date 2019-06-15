//Probably not completely correct..

#include <cstdio>
#include <cstring>

int n,k,a[103333],num;
bool t[103333],q[103333];
int ans;

int _min=0x3f2f1f0f;


void _deb()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",t[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n\n");
    return ;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("min.in","r",stdin);
    freopen("min.out","w",stdout);
    #endif
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<_min) 
        {
            _min=a[i];
        }
    }
    // printf("min=%d\n",_min);
    for(int i=1;i<=n;i++)
    {
        // _deb();
        if(a[i]==_min) t[i]=1;
        else t[i]==0; 
        if(t[i]==1)
        {
            for(int j=0;j<=k-1;j++)
            {
                q[i-j]=t[i];
            } 
        }
    }
    for(int i=1;i<n;i++)
    {
        // #ifdef ONLINE_JUDGE
        // printf("%d\n",i);
        // _deb();
        // #endif
        // if(t[i]==1&&q[i]==1) continue;
        // for(int j=0;j<=k-1;j++)
        // {
        //     t[i+j]=1;
        //     q[i+j]=1;
        //     q[i-j]=1;
        // }
        // ans++;
        if(t[i]==1&&q[i]==1&&t[i+1]==1&&q[i+1]==1) continue;
        if(t[i]==1&&q[i]==1&&t[i+1]==0&&q[i+1]==1)
        {
            i++;
            for(int j=0;j<=k-1;j++)
            {
                t[i+j]=1;
                q[i+j]=1;
                q[i+j-k]=1;
            }
            ans++;
        }
        if(t[i]==1&&q[i]==1&&q[i+1]==0)
        {
            for(int j=1;j<=k-1;j++)
            {
                t[i+j]=1;
                q[i+j]=1;
                q[i+j-k]=1;
            }
            ans++;
        }
        // printf("%d\n\n",ans);
    }
    for(int i=n;i>1;i--)
    {
        // #ifdef ONLINE_JUDGE
        // printf("%d\n",i);
        // _deb();
        // #endif
        if(t[i]==1&&q[i]==1&&t[i-1]==1&&q[i-1]==1) continue;
        if(t[i]==1&&q[i]==1&&t[i-1]==0&&q[i-1]==1)
        {
            i--;
            for(int j=0;j<=k-1;j++)
            {
                t[i-j]=1;
                q[i-j]=1;
                q[i-j-k]=1;
            }
            ans++;
        }
        if(t[i]==1&&q[i]==1&&q[i-1]==0)
        {
            for(int j=1;j<=k-1;j++)
            {
                t[i-j]=1;
                q[i-j]=1;
                q[i-j-k]=1;
            }
            ans++;
        }
    //    printf("%d\n\n",ans);

    }
    printf("%d",ans);
    return 0;
}