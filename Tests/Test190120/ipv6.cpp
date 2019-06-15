//Perhaps there are some hidden points that I even don't mension!

#include<cstdio>
#include<cstring>

#define debd(x) printf("Debug:Var=%d\n",x)
#define debs(x) printf("Debug:Var=%s\n",x)
const int _deb=23333333;

char _ipv6[64];

struct ipstr
{
    char p[5];
    bool used;
    int pl;
}a[10];

bool _valid(int len)
{
    int contcomma=0;
    int coount2=0;
    int coount=0;//On Purpose
    int phraselen=0;
    for(int i=1;i<=len;i++)
    {
        //printf("DEB:co=%d cm=%d,pr=%d i=%d\n",coount,contcomma,phraselen,i);
        if((_ipv6[i]<'0'||_ipv6[i]>'9')&&(_ipv6[i]<'A'||_ipv6[i]>'F')&&(_ipv6[i]!=':')) return false;
        if(_ipv6[i]==':')
        {
            contcomma++;
            coount++;
            if(coount>7) return false;
            if(contcomma>2) return false;
            phraselen=0;
        }
        else
        {
            if(contcomma>1) coount2++;
            contcomma=0;
            phraselen++;
            if(phraselen>4) return false;
        }
    }
    if(coount2>1) return false;
    if(coount<2) return false;
    if(coount<7&&coount2==0&&_ipv6[len]!=':') return false;
    if(coount2==1&&coount==7) return false;
    if(contcomma==2&&_ipv6[len]==':'&&coount2==1) return false;
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("ipv6.in","r",stdin);
    freopen("ipv6.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<+8;i++)
        {
            a[i].pl=1;
        }
        scanf("%s",_ipv6+1);
        int _len=strlen(_ipv6+1);
        if(_valid(_len)==0)
        {
            printf("INVALID\n");
            continue;
        }
        int countN=0;
        int _N=1;
        for(int i=1;i<=_len;i++)
        {
            if(_ipv6[i]==':')
            {
                if(_ipv6[i+1]==':')
                {
                    break;
                }
                _N++;
            }
            else
            {
                a[_N].used=1;
                a[_N].p[a[_N].pl++]=_ipv6[i];
            }
        }
        for(int i=1;i<=8;i++)
        {
            if(a[i].used==0) a[i].pl=4;
            if(a[i].used==1) a[i].pl=5-a[i].pl;
        }
        if(_N!=8)
        {
        
        _N=8;
        for(int i=_len;i>=1;i--)
        {
            if(_ipv6[i]==':')
            {
                if(_ipv6[i+1]==':')
                {
                    break;
                }
                _N--;
            }
            else
            {
                a[_N].p[a[_N].pl--]=_ipv6[i];
            }
        }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=a[i].pl;j++)
            {
                printf("0");
            }
            for(int j=1;j<=4;j++)
            {
                if(a[i].p[j]) printf("%c",a[i].p[j]);
            }
            if(i!=8)printf(":");
        }
        printf("\n");
    }
    return 0;
}