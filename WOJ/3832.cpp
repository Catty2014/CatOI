#include <cstdio>
#include <queue>
#include <cstring>

const int N=1000232/2;
const int M=1e4+233;

class Trie
{
public:
    int nx[N][26],f[N],e[N];
    int r0,l;
    int add()
    {
        for(int i=0;i<26;i++)
        {
            nx[l][i]=-1;
        }
        e[l++]=0;
        return l-1;
    }
    void init()
    {
        l=0;
        r0=add();
    }
    void insert(char s[])
    {
        int ln=strlen(s);
        int cur=r0;
        for(int i=0;i<ln;i++)
        {
            if(nx[cur][s[i]-'a']==-1)
            {
                nx[cur][s[i]-'a']=add();
            }
            cur=nx[cur][s[i]-'a'];
        }
        e[cur]++;
    }
    void build()
    {
        std::queue <int> q;
        f[r0]=r0;
        for(int i=0;i<26;i++)
        {
            if(nx[r0][i]==-1)
            {
                nx[r0][i]=r0;
            }
            else
            {
                f[nx[r0][i]]=r0;
                q.push(nx[r0][i]);
            }
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int i=0;i<26;i++)
            {
                if(nx[cur][i]==-1)
                {
                    nx[cur][i]=nx[f[cur]][i];
                }
                else
                {
                    f[nx[cur][i]]=nx[f[cur]][i];
                    q.push(nx[cur][i]);
                }
            }
        }
    }
    int query(char s[])
    {
        int ln=strlen(s);
        int cur=r0;
        int ans=0;
        for(int i=0;i<ln;i++)
        {
            cur=nx[cur][s[i]-'a'];
            int tmp=cur;
            while(tmp!=r0)
            {
                ans+=e[tmp];
                e[tmp]=0;
                tmp=f[tmp];
            }
        }
        return ans;
    }
}ac;

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
        int n;
        scanf("%d",&n);
        ac.init();
        for(int i=0;i<n;i++)
        {
            char s[M];
            scanf("%s",s);
            ac.insert(s);
        }
        ac.build();
        char s[M*100];
        scanf("%s",s);
        printf("%d\n",ac.query(s));
    }
}
