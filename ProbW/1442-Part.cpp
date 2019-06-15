/* LDWOJ #1442 最大子段和
 * Mtd:Partition
 * Easily Accepted
 */

#include <cstdio>

int p[233333];

int maxintv(int *a,int _l,int _r)
{
    if(_l==_r)
    {
        return a[_l]>0?a[_l]:0;
    }
    int _m=(_l+_r)>>1;
    int _lmaxintv=maxintv(a,_l,_m);
    int _rmaxintv=maxintv(a,_m+1,_r);
    int ans=0;
    int _lmax=0;
    for(int i=_m;i>=_l;--i)
    {
        ans+=a[i];
        if(ans>_lmax)
        {
            _lmax=ans;
        }
    }
    ans=0;
    int _rmax=0;
    for(int i=_m+1;i<=_r;++i)
    {
        ans+=a[i];
        if(ans>_rmax)
        {
            _rmax=ans;
        }
    }
    int _ret=_lmax+_rmax;
    if(_ret<_lmaxintv) _ret=_lmaxintv;
    if(_ret<_rmaxintv) _ret=_rmaxintv;
    return _ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("%d\n",maxintv(p,1,n));
    return 0;
}