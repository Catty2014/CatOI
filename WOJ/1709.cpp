#include <cstdio>
typedef long long ll;

#define max(a,b) ((a>b)?a:b)

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    ll ax,ay,bx,by;
    while(scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by)!=-1)
    {
        ll k,b;
        b=max(ay,by);
        if(ax==bx||ay==by)
        {
            printf("Error\n");
            continue;
        }
        k=b/(-1*((ay==0)?ax:bx));
        if(b>0)
        {
            if(k!=1&&k!=-1)printf("y=%lldx+%lld\n",k,b);
            if(k==1) printf("y=x+%lld\n",b);
            if(k==-1) printf("y=-x+%lld\n",b);
        }
        if(b<0)
        {
            b=-b;
            if(k!=1&&k!=-1)printf("y=%lldx-%lld\n",k,b);
            if(k==1) printf("y=x-%lld\n",b);
            if(k==-1) printf("y=-x-%lld\n",b);
        }
        if(b==0)
        {

            if(k!=1&&k!=-1)printf("y=%lldx\n",k);
            if(k==1) printf("y=x\n");
            if(k==-1) printf("y=-x\n");
        }
    }

}
