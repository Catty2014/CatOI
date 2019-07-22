#include <cstdio>
#include <queue>
#include <cstring>
#define C(i) (i-'a')

const int N=30;
const int M=2333333;

int m,n;
int tr[N][N];//Trie tree
int ed[N];
int si;//size
int ls[N];//last

void ins(char s[])
{
    int ln=strlen(s);
    int nw=1;
    for(int i=0;i<ln;i++)
    {
        int t=C(s[i]);
        if(!tr[nw][t]) tr[nw][t]=++si;
        nw=tr[nw][t];
    }
    ed[nw]=1;
}

std::queue <int> q;//Queue

void genfail()
{
    q.push(1);
    ls[1]=0;
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
        for(int i=0;i<=26;i++)
        {
            if(!tr[nw][i])
            {
                tr[nw][i]=tr[ls[nw]][i];
                continue;
            }
            int k=ls[nw];
            while(!tr[k][i]) k=ls[k];
            ls[tr[nw][i]]=tr[k][i];
            nx[[nw][i]];
        }
    }
}

int find(char s[])
{
    int ln=strlen(s);
    int nw=1;
    int ans=0;
    for(int i=0;i<ln;i++)
    {
        
    }

}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char s[23];
        scanf("%s",s);
        ins(s);
    }
    genfail();
    for(int i=1;i<=m;i++)
    {
        char s[M];
        printf("%d\n",find(s));
    }
    return 0;
}
