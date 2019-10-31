//STD

#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=55;
int mx[N][N],mn[N][N];
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,p,q;
    scanf("%d %d %d",&n,&p,&q);
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s);
        int l=strlen(s);
        for(int j=0;j<l;j++)
        {
            if(s[j]=='='||i==j+1)
            {
                mx[i][j+1]=0,mn[i][j+1]=0;
            }
            if(s[j]=='+')
            {
                mx[i][j+1]=2,mn[i][j+1]=1;
            }
            if(s[j]=='-')
            {
                mx[i][j+1]=-1,mn[i][j+1]=-2;
            }
            if(s[j]=='?')
            {
                mx[i][j+1]=2,mn[i][j+1]=-2;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=k)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i!=j&&k!=j)
                    {
                        mx[i][j]=std::min(mx[i][j],mx[i][k]+mx[k][j]);
                        mn[i][j]=std::max(mn[i][j],mn[i][k]+mn[k][j]);
                    }
                }
            }
        }
    }
    int lss = 0,equ = 0,gtr = 0;
    for(int i=1;i<=n;i++)
    {
        if(i!=p&&i!=q)
        {
            for(int j=1;j<i;j++)
            {
                if(j!=p&&j!=q)
                {
                    if(mn[p][i]>mx[j][q]||mn[p][j]>mx[i][q])
                    {
                        lss++;
                    }
                    if(mn[j][q]>mx[p][i]||mn[j][p]>mx[q][i])
                    {
                        gtr++;
                    }
                    if((mx[p][i]==mn[p][i]&&mx[j][q]==mn[j][q]&&mx[p][i]==mx[j][q])||(mx[p][j]==mn[p][j]&&mx[i][q]==mn[i][q]&&mx[p][j]==mx[i][q]))
                    {
                        equ++;
                    }
                }
            }
        }
    }
    printf("%d %d %d\n",lss,equ,gtr);
    return 0;
}
