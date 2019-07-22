//SDOJ #3303 Journey
//Language:C++
//Difficulty:Lv.3
//Method:Partition
//Working...

#include <cstdio>

#define _ID 1
#define _M ((l+r)>>1)

long long a[133333];
long long ans;
int m,n;//M:road,N:day

long long check(int v)
{
    int ret=0;
    int tmp=0;
    bool first=1;
    for(int i=1;i<=n;i++)
    {
        //if(a[i]>v) return 0x7f6f5f4f;
        tmp+=a[i];
        if(tmp>v)
        {
            tmp=a[i];
            ret++;
            continue;
        }
    }
    return ret;
}

long long calc(long long l,long long r)
{
        while(l < r)
        {
            //printf("%d %d %d\n",l,r,check(_M));
            //printf("%d\n",_M);
            if(check(_M)<(long long)m) r=_M-1;
            else l=_M+1;
        }
    return l;
}

void findroad(long long ans)
{
    int nnn=n;
    int ret=0;
    int tmp=0;
    bool first=1;
    for(int i=1;i<=n;i++)
    {
        tmp+=a[i];
        if(tmp>ans)
        {
            if(first==0) i--;
            tmp=0;
            first=1;
            printf("%d %d ",nnn-1,nnn);
        }
        first=1;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int _l=0,_r=(int)0x7f6f5f4f;
    ans=calc(_l,_r);
    if(_ID)
    {
        printf("%lld\n",ans);
    }
    else
    {
        printf("1 ");
        findroad(ans);
    }
    return 0;
}