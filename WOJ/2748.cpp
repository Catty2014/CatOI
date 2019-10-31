//来嘛，模拟就模拟

#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=112;
const int M=148;
bool u[666];
int loop;
int hasx[M];
bool err=0;
int lsch[M];
int cnt;
int edlp;
int ans=0;
int opt;
char targ[M];
int cn=0;
int xx;
int yy;
int rans=-1;

int toint(char c[])
{
    int ret=0;
    int cnp=strlen(c);
    for(int i=0;i<=cnp-1;i++)
    {
        ret*=10;
        ret+=c[i]-'0';
    }
    cnp=0;
    return ret;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(lsch,0,sizeof(lsch));
        memset(hasx,0,sizeof(hasx));
        memset(targ,0,sizeof(targ));
        loop=0;
        cnt=0;
        cn=0;
        opt=0;
        ans=0;
        edlp=0;
        rans=0;
        err=0;
        memset(u,0,sizeof(u));
        int n;
        scanf("%d",&n);
        char o[N];
        scanf("%s",o);
        char p[N];
        for(int i=1;i<=n;i++)
        {
            scanf("%s",p);
            if(p[0]=='F')
            {
                memset(p,0,sizeof(p));
                loop++;
                for(int i=1;i<=3;i++)
                {
                    scanf("%s",p);
                    if(i==1)
                    {
                        if(u[p[0]]==1&err==0)
                        {
                            printf("ERR\n");
                            err=1;
                            continue;
                        }
                        u[p[0]]=true;
                        lsch[++cnt]=p[0];
                    }
                    if(i==2)
                    {
                        if(p[0]=='n')
                        {
                            xx=-1;
                        }
                        else
                        {
                            xx=toint(p);
                        }

                    }
                    if(i==3)
                    {
                        if((p[0]=='n')&&(edlp==0)&&(xx!=-1))
                        {
                            hasx[loop]=1;
                        }
                        if(p[0]=='n')
                        {
                            yy=-1;
                        }
                        if(p[0]!='n')
                        {
                            yy=toint(p);
                        }
                        if(xx>yy &&edlp==0 &&yy!=-1)
                        {
                            edlp=loop;
                        }
                        if(xx==-1&&yy!=-1 && edlp==0)
                        {
                            edlp=loop;
                        }
                    }
                    memset(p,0,sizeof(p));
                    continue;
                }
            }
            if(p[0]=='E')
            {
                for(int i=1; i<=loop; i++)
                {
                    if(hasx[i]==1)
                        ans++;
                }
                if(ans>rans)
                    rans=ans;
                ans=0;
                hasx[loop]=0;
                loop--;
                u[lsch[cnt--]]=0;
                if(loop==edlp)
                {
                    edlp=0;
                }

            }
        }
        if(loop!=0&&err==0)
        {
            printf("ERR\n");
            err=1;
            continue;
        }
        cn=-1;
        for(int i=0;i<=strlen(o);i++)
        {
            if(o[i]=='^')
            {
                for(i++;i<=strlen(o);i++)
                {
                    if(o[i]==')') break;
                    targ[++cn]=o[i];
                }
                opt=toint(targ);
            }
            if(o[i]=='1'&&o[i-1]=='(')
            {
                opt=0;
            }
        }
        if(opt==rans&&err==0)
        {
            printf("Yes\n");
        }
        if(opt!=rans&&err==0)
        {
            printf("No\n");
        }
    }
}
