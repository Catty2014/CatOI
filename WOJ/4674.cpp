#include <cstdio>
#include <cstring>
#include <algorithm>

namespace RND{
    long long seed;int n;
    inline void init(){
        int t;
        scanf("%d",&t);seed=t;
    }

    inline long long rnd(){
        seed^=seed<<17;
        seed^=seed>>6;
        seed^=seed<<5;
        if(seed<0)seed=(unsigned int)seed;
        return seed;
    }

    inline void getQuery(int &l,int &r){
        l=rnd()%n+1,r=rnd()%n+1;
        if(l>r)std::swap(l,r); 
    }
}
using RND::getQuery;

const int N=5e6+233;
char s[N];
int n,m;
int a[N];

int nn[N],oo[N],ii[N];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    scanf("%s",s+1);
    int ln=strlen(s+1);
    RND::n=ln;
    RND::init();
    /* for(int i=1;i<=n;i++) */
    /* { */
    /*     if(s[i]=='n') */ 
    /*     { */
    /*         nn[i]=nn[i-1]+1; */
    /*         oo[i]=oo[i-1]; */
    /*         ii[i]=ii[i-1]; */
    /*     } */
    /*     if(s[i]=='o') */ 
    /*     { */
    /*         nn[i]=nn[i-1]; */
    /*         oo[i]=oo[i-1]+nn[i]; */
    /*         ii[i]=ii[i-1]; */
    /*     } */
    /*     if(s[i]=='i') */
    /*     { */
    /*         nn[i]=nn[i-1]; */
    /*         oo[i]=oo[i-1]; */
    /*         ii[i]=ii[i-1]+oo[i]; */
    /*     } */
    /*     printf("nn=%d oo=%d ii=%d\n",nn[i],oo[i],ii[i]); */
    /* } */
    unsigned long long ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(nn,0,sizeof(nn));
        memset(oo,0,sizeof(oo));
        memset(ii,0,sizeof(ii));
        int l,r;
        RND::getQuery(l,r);
        for(int i=l;i<=r;i++)
        {
            if(s[i]=='n') 
            {
                nn[i]=nn[i-1]+1;
                oo[i]=oo[i-1];
                ii[i]=ii[i-1];
            }
            if(s[i]=='o') 
            {
                nn[i]=nn[i-1];
                oo[i]=oo[i-1]+nn[i];
                ii[i]=ii[i-1];
            }
            if(s[i]=='i')
            {
                nn[i]=nn[i-1];
                oo[i]=oo[i-1];
                ii[i]=ii[i-1]+oo[i];
            }
        }
        ans^=ii[r];
        /* printf("%d %d %llu\n",l,r,ans); */
    }
    printf("%llu\n",ans);
}
