//看来没办法定义 < 符号呢...
//2^32-1

#include <cstdio>
#include <algorithm>
#include <iostream>

using std::lower_bound;
using std::sort;

typedef long long ll;

#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))

ll A[3333333],B[133];
ll w;//GB!WCLZ!
int n;
int _a=0;//count of A
int _min=0x3fffffff;//what for?
ll ans;

inline bool srt(const ll a,const ll b)
{
    return a>b;
}

void df1(int l,int r,ll _n)//L Part search
{
    if(_n>w) return ;
    A[++_a]=_n; 
    _min=MIN(_min,_n);
    for(int i=l;i<=r;i++)
    {
        df1(i+1,r,(ll)_n+B[i]);
    }
}

void df2(int l,int r,ll _n)//R part search
{
    if (_n+_min>w) return ; //He can't fetch these things
    if(l>r)
    {
        int _t=w-_n;//max req
        int _p=lower_bound(A,A+_a,_t)-A;
        if(_p==0&&A[_p]>_t) return ; //???
        if(_p==0&&A[_p]==_t) 
        {
            ans=w;
            return ;
        }
        ans=MAX(ans,A[_p-1]+_n);
        return ;
    }
    df2(l+1,r,_n);
    df2(l+1,r,_n+B[l]);
}

int main()
{
    scanf("%lld %d",&w,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&B[i]);
    }
    sort(B+1,B+n+1,srt);//Much faster using sort
    df1(1,n/2,0);
    sort(A,A+_a);
    df2((n/2+1),n,0);
    printf("%lld\n",ans);
    return 0;
}