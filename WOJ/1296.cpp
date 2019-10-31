#include <cstdio>

int a[600];

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);
    int k=n;
    int p=0;
    int pass=0;
    for(int i=2;;i++)
    {
        int sp=i%n;
        if(sp==0)
            sp=n;
        if(a[sp]==1) continue;
        if(pass==1) 
        {
            pass=0;
            continue;
        }
        if(k==1)
        {
            printf("%d\n",sp);
            return 0;
        }
        p++;
        if(p==m)
        {
            a[sp]=1;
            p=0;
            k--;
            pass=1;
        }
    }
    return 0;
}
