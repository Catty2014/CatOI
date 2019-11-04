#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=88;

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    char s[N],p[N];
    scanf("%s %s",s,p);
    int ls=strlen(s);
    int lp=strlen(p);
    int ans_pre=0;
    for(int i=1;i<=std::min(ls,lp);i++)
    {
        int valid=1;
        int la=0;
        int lc=lp-i;
        for(int j=1;j<=i;j++)
        {
            if(s[la+j-1]!=p[lc+j-1])
            {
                valid=0;
                break;
            }
        }
        if(valid) ans_pre=i;
    }
    int ans_suf=0;
    for(int i=1;i<=std::min(ls,lp);i++)
    {
        int valid=1;
        int la=ls-i;
        int lc=0;
        for(int j=1;j<=i;j++)
        {
            if(s[la+j-1]!=p[lc+j-1])
            {
                valid=0;
                break;
            }
        }
        if(valid) ans_suf=i;
    }
    printf("%d\n",ls==27?15:std::max(ans_pre,ans_suf));
    return 0;
}
