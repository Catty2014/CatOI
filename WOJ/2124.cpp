#include <cstdio>
#include <cstring>

const int N=1e6+2333;
char s[N],p[N];
int f[N];
int ls,lp=0;

void genF()
{
    f[0]=f[1]=0;
    int k=0;
    for(int j=1;j<lp;j++)
    {
        while(k&&p[j]!=p[k]) k=f[k];
        if(p[j]==p[k]) k++;
        f[j+1]=k;
    }
}

int kmp()
{
    genF();
    int ans=0;
    int j=0,i=0;
    while(i<ls && j<lp)
    {
        while(j&&p[j]!=s[i]) j=f[j];
        if(p[j]==s[i]) j++;
        if(j==lp) ans++,j=f[j];
        i++;
    }
    return ans;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%s",s);
    scanf("%s",p);
    ls=strlen(s);
    lp=strlen(p);
    printf("%d\n",kmp());
    return 0;
}
