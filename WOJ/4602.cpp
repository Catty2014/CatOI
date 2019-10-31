#include <cstdio>
#include <cstring>

const int N=1e6;
char s[N],p[N];
int pres[N],prep[N];
int l[333];
int f[N];

#define EQ(a,b,l) (a==b||((a>l)&&(b>l)))


int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%s %s",s+1,p+1);
        int ls,lp;
        ls=strlen(s+1);
        lp=strlen(p+1);
        memset(l,0,sizeof(l));
        for(int i=1;i<=lp;i++)
        {
            if(p[i]>='a'&&p[i]<='z')
            {
                prep[i]=i-l[(int)p[i]];
                l[(int)p[i]]=i;
            }
            else
            {
                prep[i]=-p[i];
            }
        }
        memset(l,0,sizeof(l));
        for(int i=1;i<=ls;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                pres[i]=i-l[(int)s[i]];
                l[(int)s[i]]=i;
            }
            else
            {
                pres[i]=-s[i];
            }
        }
        int j=f[0]=f[1]=0;
        for(int i=2;i<=lp;i++)
        {
            while(j&&!EQ(prep[j+1],prep[i],j)) j=f[j];
            if(EQ(prep[j+1],prep[i],j)) j++;
            f[i]=j;
        }
        j=0;
        int ans=0;
        for(int i=1;i<=ls;i++)
        {
            while(j&&!EQ(prep[j+1],pres[i],j)) j=f[j];
            if(EQ(prep[j+1],pres[i],j)) j++;
            if(j==lp)
            {
                ans++;
                j=f[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
