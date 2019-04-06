#include <cstdio>

bool cont=true;
int a[2633];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("orz.in","r",stdin);
    freopen("orz.out","w",stdout);
    #endif
    int M,N;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==2) tmp=1;
        else tmp=-1;
        a[i]=tmp;
    }
    int i=1,j=1;
    int sum=0;
    int ans=0;
    while(i<=N)
    {
        // printf("%d %d\n",i,ans);
        j++;
        if(j>N)
        {
            ans++;
            break;
        }
        sum+=a[j];
        // printf("a[%d]=%d a[%d]=%d\n",j,a[j],j-1,a[j-1]);
        if(a[j]==a[j-1]&&cont==true) 
        {
            continue;
        }
        else cont=false;

        if(sum==M||sum==-M||(cont==false&&(sum>=M||sum<=-M)))
        {
            sum=0;
            ans++;
            cont=true;
            i=j;
        }
        // printf("s=%d %d\n",sum,M);
    }
    //if(sum<M) ans++;
    printf("%d\n",ans);
    return 0;
}