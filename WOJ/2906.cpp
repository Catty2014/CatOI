#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

const int N=200;
const int CHR=26;
const int M=2333333;
#define C(i) (i-'a')
int ch[N][28];
int cn;
int val[N];
int ls[N];
int f[N];
char t[M];
int ac[N];
int ans=0;
int cac[N];
char src[N][N];
int ccn=1;

void ins(char s[],int v)
{
    int ln=strlen(s);
    int u=0;
    for(int i=0;i<ln;i++)
    {
        int c=C(s[i]);
        if(!ch[u][c])
        {
            memset(ch[++cn],0,sizeof(ch[cn]));
            ch[u][c]=cn;
        }
        u=ch[u][c];
    }
    val[u]=v;
}

void gfail()
{
    std::queue <int> q;
    for(int i=0;i<CHR;i++)
    {
        if(ch[0][i] )q.push(ch[0][i]);
    }
    while(!q.empty())
    {
        int r=q.front();
        q.pop();
        for(int i=0;i<CHR;i++)
        {
            int u=ch[r][i];
            if(!u)
            {
                ch[r][i]=ch[f[r]][i];
                continue;
            }
            int v=f[r];
            f[u]=ch[v][i];
            ls[u]=val[f[u]]?f[u]:ls[f[u]];
            q.push(u);
        }
    }
}

void fn(char t[])
{
    int len=strlen(t);
    int u=0;
    for(int i=0;i<len;i++)
    {
        int c=C(t[i]);
        u=ch[u][c];
        if(val[u])
        {
            ac[u]+=ac[u];
        }
        else if (ls[u]) 
        {
            ac[u]+=ac[ls[u]];
        }
    }
}

int n;
char s[N];

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    while(1)
    {
        memset(ch,0,sizeof(ch));
        memset(t,0,sizeof(t));
        memset(val,0,sizeof(val));
        memset(ls,0,sizeof(ls));
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            strcpy(src[i],s);
            ins(s,i);
        }
        gfail();
        scanf("%s",t);
        fn(t);
        for(int i=1;i<=n;i++)
        {
            if(ac[i]==ans)
            {
                cac[ccn++]=i;
            }
            if(ac[i]>ans)
            {
                ccn=1;
                cac[ccn++]=i;
            }
            ans=std::max(ans,ac[i]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=ccn;i++)
        {
            printf("%s\n",src[cac[i]]);
        }
    }

}
