//ST=SmT=SegmentTree
#include <cstdio>
#include <algorithm>

using std::max;

struct SmT
{
    int l,r;
    int ls,rs,ms,sm;//SM-->MS
    //ls:LMax,rs:RMax,ms:TotalMax,Sm:Sum
}s[403333];
//Suddenly,I remembered that SegmntTree should use 4 times space...

int n,m,op;

void st_build(int p,int q,int r)
{
    s[p].l=q;
    s[p].r=r;
    if(q==r) return ;
    st_build((p<<1),q,((q+r)>>1));
    st_build(((p<<1)|1),(((q+r)>>2)|1),r);
    return ;
}  

void st_ins(int p,int q,int r)
{
    if(s[p].r==s[p].l) 
    {
        s[p].ls=s[p].rs=s[p].sm=s[p].ms=r;
        return ;
    }
    if(((s[p].r+s[p].l)<<1 )<q)
    {
        st_ins(p*2+1,q,r);
    }
    else
    {
        st_ins(p*2,q,r);
    }
    int g=p*2;
    s[p].ls=max(s[g].sm+s[g+1].ls,s[g].ls);
    s[p].rs=max()
    

}

int main()
{
    scanf("%d %d",&n,&m);
    st_build(1,1,n);
    for (int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        st_ins(1,i,p);
    }
}