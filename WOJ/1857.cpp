//讲真，这似乎不是DP
#include <cstdio>

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int m,s,t;
    int p=0,q=0;
    scanf("%d %d %d",&m,&s,&t);
    while(m>=10)
    {
        p++;
        q+=60;
        m-=10;
        if(q>=s)
        {
            printf("Yes\n%d\n",p);
            return 0;
        }
        if(p>=t)
        {
            printf("No\n%d\n",q);
            return 0;
        }
    }
    while(t>p)
    {
        int sp=0;
        if(t-p>=7&&s-q>=120)
        {
            p+=7;
            q+=120;
            sp=1;
        }
        if(sp==0)
        {
            int rt=(10-m)/4;
            if((10-m)%4) rt++;
            if((rt+1)*17<60)
            {
                p+=rt+1;
                m=rt*4+m-10;
                q+=60;
                sp=1;
            }
        }
        if(sp==0)
        {
            p++;
            q+=17;
        }
        if(q>=s)
        {
            printf("Yes\n%d\n",p);
            return 0;
        }
    }
    printf("No\n%d\n",q);
    return 0;
}
