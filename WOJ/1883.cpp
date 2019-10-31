#include <cstdio>

int a[15];
int s;
int l;
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    for(int i=1;i<=12;i++)
    {
        scanf("%d",&a[i]);
        l=(300+l-a[i]);
        if(l>=100)
        {
            s+=(int)(l/100)*100;
            l%=100;
        }
        if(l<0)
        {
            printf("%d\n",-i);
            return 0;
        }
    }
    printf("%d",s*6/5+l);
    return 0;
}
