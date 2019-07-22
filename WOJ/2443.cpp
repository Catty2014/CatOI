//Mo's Algo

#include <cstdio>
#include <algorithm>
#include <cmath>

#define tml tmp[a[l]]
#define tmr tmp[a[r]]
//WHY R U SO AWKWARD!!!

const int N=133333;
int n,m,c,k;
int a[N],idx[N],tmp[N];
struct L
{
    int l,r,ans,id;
}q[N];

bool cmp2(const L&a,const L&b)
{
    if(idx[a.l]==idx[b.l]) return a.r<b.r;
    return a.l<b.l;
}

bool cmp (const L&a,const L&b)
{
    return a.id<b.id;
}

void _sol()
{
    int l=0,r=0;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r)
        {
            r++;
            tmp[a[r]]++;
            if(tmr%2==0) ans++;
            if(tmr%2==1 && tmr!=1) ans--;
        }
        // printf("ans==%d\n",ans);
        while(l>q[i].l)
        {
            l--;
            tml++;
            if(tml%2==0) ans++;
            if(tml%2==1 && tml!=1) ans--;
        }
        // printf("ans==%d\n",ans);
        while(r>q[i].r)
        {
            tmr--;
            if(tmr%2==0 && tmr!=0) ans++;
            if(tmr%2==1) ans--;
            r--;
        }
        // printf("ans==%d\n",ans);
        while(l<q[i].l)
        {
            tml--;
            if(tml%2==0 && tml!=0) ans++;
            if(tml%2==1) ans--;
            l++;
        }
        q[i].ans=ans;
        // printf("ans==%d\n",ans);
    }
}

int main()
{
    scanf("%d %d %d",&n,&c,&m);
    k=(int)std::sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        idx[i]=(i-1)/k +1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    std::sort(q+1,q+m+1,cmp2);
    _sol();
    std::sort(q+1,q+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",q[i].ans);
    }
    return 0;
}