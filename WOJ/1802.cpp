#include <cstdio>
#include <cstring>

typedef long long ll;

ll n[666666],p;
int cn;
char s[1233333];
int rl=-1;

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%s",s);
    int ln=strlen(s);
    int num=0;
    for(int i=0;i<=ln;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            num*=10;
            num+=s[i]-'0';
            num%=10000;
        }
        if(s[i]=='+')
        {
            n[++cn]=num;
            num=0;
            if(rl!=-1)
            {
                ll tmp=1;
                for(int i=rl;i<=cn;i++)
                {
                    tmp*=n[i];
                    tmp%=10000;
                }
                cn=rl;
                n[cn]=tmp;
                rl=-1;
            }
        }
        if(s[i]=='*')
        {
            n[++cn]=num;
            num=0;
            if(rl==-1)rl=cn;
        }
        if(i==ln)
        {
            n[++cn]=num;
            num=0;
            if(rl!=-1)
            {
                ll tmp=1;
                for(int i=rl;i<=cn;i++)
                {
                    tmp*=n[i];
                    tmp%=10000;
                }
                cn=rl;
                n[cn]=tmp;
                rl=-1;
            }
            n[++cn]=num;
            num=0;
            ll tmp=0;
            for(int i=1;i<=cn;i++)
            {
                tmp+=n[i];
                tmp%=10000;
            }
            printf("%lld\n",tmp%10000);
        }
    }
}
