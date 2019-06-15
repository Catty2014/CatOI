#include<cstdio>
typedef long long ll;
int n,ans=1,num=1;
int p[15]={1,2,3,5,7,11,13,17,19,23,29};

void dfs(int k,ll now,int cnt,int last)
{
    if(k==11)
    {
        if(now>ans&&cnt>num) ans=now,num=cnt;
        if(now<=ans&&cnt>=num) ans=now,num=cnt;
        return ;
    }
    int t=1;
    for(int i=0;i<=last;i++)
    {
        dfs(k+1,now*t,cnt*(i+1),i);
        t*=p[k];
        if(now*t>n) break;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    dfs(1,1,1,20);
    printf("%d\n",ans);
    return 0;
}
