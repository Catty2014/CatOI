//ORZ___

#include <cstdio>

int num[3000];
int sum[3000];
int first;
int M,N;

void search(int i)
{
    first=num[i];
    for(int j=N;j>=i;j++)
    {
        if(sum[j]==M) 
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("orz.in","r",stdin);
    freopen("orz.out","w",stdout);
    #endif
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1) tmp=-1;
        if(tmp==2) tmp=1;
        num[i]=tmp;
        sum[i]=sum[i-1]+tmp;
    }
    int ans=0;
    printf("%d\n",ans);
    return 0;
}
