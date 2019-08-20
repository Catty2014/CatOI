#include <cstdio>
#include <cmath>
#include <cstring>

const int N=50233;
const int M=1000233;
typedef long long ll;

int p[N];
int pn;
int np[M],P[M],PN;
/*Alternative Name:
int prime1[N];
int prime1Count;
int isNotPrime[M],prime2[M],prime2Count;
*/

void eulerPrimer(int r)
{
    memset(p,0,sizeof(p));
    pn=0;
    for(int i=2;i<r;i++)
    {
        if(!p[i]) p[++pn]=i;
        for(int j=1;j<=pn && i*p[j]<r;j++)
        {
            p[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }
}

void eraPrimer(int l,int r)
{
    memset(np,0,sizeof(np));
    memset(P,0,sizeof(P));
    PN=0;
    l=(l<=2)?2:l;
    for(int i=1;i<pn&&(ll)p[i]*(ll)p[i]<=r;i++)
    {
        int s=ceil((double)l/(double)p[i]);
        /* int s=l/p[i]+(l%p[i]!=0); */
        if(s==1)
        {
            s=2;
        }
        for(int j=s;(ll)j*(ll)p[i]<=r;j++)
        {
            if((ll)j*p[i]>=l)
            {
                np[j*p[i]-l]=1;
            }
        }
    }
    for(int j=0;j<=r-l;j++)
    {
        if(!np[j]) P[++PN]=j+l;
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    eulerPrimer(50000);
    int l,r;
    while(scanf("%d %d",&l,&r)!=-1)
    {
        eraPrimer(l,r);
        if(PN<2) printf("There are no adjacent primes.\n");
        else
        {
            int lm=0,rm=0x33333333,LM=0,RM=0;
            for(int i=2;i<=PN;i++)
            {
                int d=P[i]-P[i-1];
                if(rm-lm>d)
                {
                    rm=P[i];
                    lm=P[i-1];
                }
                if(RM-LM<d)
                {
                    RM=P[i];
                    LM=P[i-1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",lm,rm,LM,RM);
        }
    }
    return 0;
}
