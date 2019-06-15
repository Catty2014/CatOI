#include <bits/stdc++.h>
using namespace std;

int n;
long double k=1.0;
const int INF=2000000000;
bool p0=0,q0=0;
int ttd=0;
long double aa,bb;

int getdig(double tg)
{
    int p=(int)tg;
    int ans=0;
    while(p)
    {
        ans++;
        p/=10;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double p,q;
        scanf("%lf %lf",&p,&q);
        aa*=p,bb*=q;
        int _digit=getdig(p)-getdig(q);

        if(p==0) p0=1;
        if(q==0) q0=1;
        if(q!=0&&p!=0) k=k*(p/q*1.0);
        if(p0==1&&q0==1) k=1;
        if(p0==1&&q0!=1) k=0;
        if(p0!=1&&q0==1) k=INF;
        cout<<k<<"\n";
        printf("%.12Lf\n",k);       
        long double delta=(k-1.000000),deltaabs=abs((k-1.000000));
        if(deltaabs>1e-9&&delta>0)
        {
            printf("A\n");
        }
        if(deltaabs>1e-9&&delta<0)
        {
            printf("B\n");
        }
        if(deltaabs<1e-9)
        {
            printf("equal\n");
        }
    }
    return 0;
}