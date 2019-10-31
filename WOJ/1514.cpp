#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

#define max(a,b) (a>b)?a:b
typedef long long ll;

const int BUFSIZE=1<<12;
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
        if(x<0) iob.putch('-'),writeInt(-x);
        if(x>9) writeInt(x/10);
        iob.putch(x%10+'0');
    }
    void writeLong(const long long x)
    {
        if(x<0) iob.putch('-'),writeLong(-x);
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


/*大型读优/大整数模板结束*/

const int N=2033;
int a[N][N];
const int dx[5]={0,1,0,-1,0};
const int dy[5]={0,0,1,0,-1};

struct Point
{
    int x,y,v;
}p[N*N];
std::queue <Point> q;

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n;
    io.readInt(n);
    for(int i=1;i<=n;i++)
    {
        char s[N];
        io.readStr(s);
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0') a[i][j+1]=1;
        }
    }
    int px,py,qx,qy;
    io.readInt(px);
    io.readInt(py);
    io.readInt(qx);
    io.readInt(qy);
    q.push((Point){px,py,0});
    while(!q.empty())
    {
        Point s=q.front();
        q.pop();
        int x=s.x;
        int y=s.y;
        int v=s.v;
        if(x==qx&&y==qy)
        {
            io.writeInt(v);
            io.flush();
            return 0;
        }
        for(int i=1;i<=4;i++)
        {
            int px=x+dx[i];
            int py=y+dy[i];
            if(a[px][py]==1)
            {
                q.push((Point){px,py,v+1});
                a[px][py]=0;
            }
        }
    }
    io.writeInt(-1);
    io.flush();
    return 0;
}
