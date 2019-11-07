#include <cstdio>
#include <cstring>
#include <algorithm>
const int BUFSIZE=1<<17;
class IO_BASE
{
private:
    char ibuf[BUFSIZE],obuf[BUFSIZE];
    char *pi1=ibuf,*pi2=ibuf;
    int po1=-1;
    const int po2=BUFSIZE-1;
public:
    char getch()
    {
        return pi1==pi2&&(pi2=(pi1=ibuf)+fread(ibuf,1,BUFSIZE,stdin),pi1==pi2)?EOF:*pi1++;
    }
    char getchar()
    {
        return std::getchar();
    }
    void putch(const char &c)
    {
        if(po1==po2) flush();
        obuf[++po1]=c;
    }
    void putchar(const char &c)
    {
        std::putchar(c);
    }
    void flush()
    {
        fwrite(obuf,1,po1+1,stdout);
        po1=-1;
    }
}iob;
#ifdef LOCALREAD
    #define getch() getchar()
    #define putch(x) putchar(x)
#endif //LOCALREAD
class IO
{
public:
    void readInt(int &v)
    {
        int f=1,x=0;char s=iob.getch();
        while(s<'0'||s>'9'){if(s=='-')f=-1;s=iob.getch();}
        while(s>='0'&&s<='9'){x=x*10+s-'0';s=iob.getch();}
        v=x*f;
    }
    void readLong(long long &v)
    {
        long long f=1,x=0;char s=iob.getch();
        while(s<'0'||s>'9'){if(s=='-')f=-1;s=iob.getch();}
        while(s>='0'&&s<='9'){x=x*10+s-'0';s=iob.getch();}
        v=x*f;
    }
    void writeInt(const int x)
    {
        if(x<0) {iob.putch('-');writeInt(-x);return;}
        if(x>9) writeInt(x/10);
        iob.putch(x%10+'0');
    }
    void writeLong(const long long x)
    {
        if(x<0) {iob.putch('-');writeLong(-x);return;}
        if(x>9) writeLong(x/10);
        iob.putch(x%10+'0');
    }
    bool notEOL(char c)
    {
        return !(c==10||c==13||c==32||c<=0);
    }
    void readStr(char* s)
    {
        char c=iob.getch();
        int t=-1;
        while(notEOL(c))s[++t]=c,c=iob.getch();
        s[++t]='\0';
    }
    void writeStr(const char* s)
    {
        for(unsigned int i=0;i<strlen(s);i++)
        {
            iob.putch(s[i]);
        }
    }
    void readChar(char &c)
    {
        c=iob.getch();
    }
    void writeChar(const char c)
    {
        iob.putch(c);
    }
    void flush()
    {
        iob.flush();
    }
}io;
//==================================================

#include <vector>


const int N=2e6+33;

int n,m;
int a[N];
int l[N],r[N];
int fa[N];
std::vector <int> v[N];
static const int M=21;
int rt[N],dep[N],anc[M][N];

class tree
{
public:
    void dfs(int u,int r0)
    {
        rt[u]=r0;
        dep[u]=(fa[u]==-1)?1:(dep[fa[u]]+1);
        anc[0][u]=fa[u];
        for(int i=1;(1<<i)<dep[u];i++)
        {
            anc[i][u]=anc[i-1][anc[i-1][u]];
        }
        #if __cplusplus >= 201101L
        for(auto x:v[u]) dfs(x,r0);
        #else
        for(int i=1;i<=v[u].size();i++)
        {
            int x=v[u][i];
            dfs(x,r0);
        }
        #endif
    }

    void build()
    {
        std::vector <int> s;
        s.clear();
        for(int i=1;i<=2*n;i++)
        {
            l[i]=std::min(i,a[i]);
            r[i]=std::max(i,a[i]);
            while(!s.empty() && s.back() >=l[i])
            {
                int p=s.back();
                s.pop_back();
                if(l[i]>l[p]) l[i]=l[p];
                if(r[i]<r[p]) r[i]=r[p];
            }
            s.push_back(i);
        }
        for(int i=0;i<=2*n;i++) rt[i]=fa[i]-1;
        for(int i=1;i<=2*n;i++) 
        {
            if(r[i]==i)
            {
                fa[i]=l[i]-1;
                v[l[i]-1].push_back(i);
            }
        }

        r[0]=0;
        for(int i=0;i<=2*n;i++)
        {
            if(!v[i].empty() && rt[i]==-1) dfs(i,i);
        }
    }

    int lca(int u,int v)
    {
        if(dep[u]<dep[v]) std::swap(u,v);
        for(int k=dep[u]-dep[v],i=0;(1<<i)<=k;i++)
        {
            if(k>>i&1) u=anc[i][u];
        }
        if(u==v) return u;
        for(int i=20;i>=0;i--)
        {
            if((1<<i)<dep[u] && anc[i][u]!=anc[i][v])
            {
                u=anc[i][u];
                v=anc[i][v];
            }
        }
        return fa[u];
    }

    int query(int r1,int r2)
    {
        return (rt[r1]==-1)||(rt[r2]==-1)||(rt[r1]!=rt[r2])?0:dep[lca(fa[r1],fa[r2])];
    }
}t;



int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    io.readInt(n);
    io.readInt(m);
    for(int i=1;i<=2*n;i++)
    {
        io.readInt(a[i]);
    }
    t.build();
    while(m--)
    {
        int r1,r2;
        io.readInt(r1);
        io.readInt(r2);
        if(r1==0||r2==0) io.writeInt(0);
        else io.writeInt(t.query(r1,r2)-1);
        io.writeChar('\n');
    }
    io.flush();
    return 0;
}

