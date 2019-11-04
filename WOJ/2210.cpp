#include <cstdio>

int a[(int)1e5+233];
int ac;
int n0;
int d[(int)1e5+233];
int ln;
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    a[++ac]=0xa3333333;
    for(int i=2;i<=n+1;i++)
    {
        int t;
        scanf("%d",&t);
        if(t) a[++ac]=t-n0;
        else ++n0;
    }
    a[++ac]=0x7fffffff;
    d[1]=a[1];
    ln=1;
    for(int i=2;i<=ac;i++)
    {
        int l=1,r=ln;
        if(d[ln]<a[i]) d[++ln]=a[i];
        else
        {
            while(l<=r)
            {
                int m=(l+r)>>1;
                if(d[m]<a[i]) l=m+1;
                else r=m-1;
            }
            d[l]=a[i];
        }
    }
    printf("%d\n",ln+n0-2);
    return 0;
}
