#include <cstdio>

int s[10002333];

int getsum(int n)
{
    if(s[n]!=0) return s[n];
    int ret=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ret+=i;
            if(n/i!=i)ret+=n/i;
        }
    }
    return s[n]=ret;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int l,r;
    scanf("%d %d",&l,&r);
    for(int i=l;i<=r;i++)
    {
        getsum(i);
    }
    for(int i=l;i<=r;i++)
    {
        if(getsum(getsum(i))==i&& getsum(i)>=l&&getsum(i)<=r && getsum(i)!=i)
        {
            printf("%d %d\n",i,getsum(i));
            s[i]=-1;
            s[getsum(i)]=-1;
        }
    }
    return 0;
}
