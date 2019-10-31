#include <cstdio>
#include <cstring>
const int BUFSIZE=1<<18;
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
const int N=5233;
int n,g[N][N];
long long x[N],f[N][N];
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    io.readInt(n);
    for(int i=1;i<=n;i++)
    {
        io.readLong(x[i]);
        x[i]+=x[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i]=x[i]-x[i-1],g[i][i]=i;
    }
    for(int k=1;k<n;k++)
    {
        for(int i=1,j,l;(j=i+k)<=n;i++)
        {
            f[i][j]=1e18;
            for(l=g[i][j-1];l<=g[i+1][j];l++)
                if(f[i][l-1]+f[l+1][j]<f[i][j])
                    f[i][j]=f[i][l-1]+f[l+1][j],g[i][j]=l;
            f[i][j]+=x[j]-x[i-1];
        }
    }
    io.writeLong(f[1][n]);
    io.flush();
    return 0;
}


