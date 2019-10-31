#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define max(a,b) (a>b)?a:b
//#undef LOCALREAD
typedef long long ll;

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


const int B=10000;

class lint
{
public:
    int ln;
    long long a[253333];
    lint()
    {
        ln=1;
        memset(a,0,sizeof(a));
    }
    lint(int n)
    {
        *this=n;
    }
    void operator = (int n)
    {
        ln=0;
        if(!n) ln=1;
        while(n)
        {
            a[++ln]=n%B,n/=B;
        }
    }
    void operator = (char* s)
    {
        ln=1;
        int ls=strlen(s);
        int k=1;
        for(int i=ls-1;i>=0;i--)
        {
            if(k>=B)
            {
                k=1;ln++;
            }
            a[ln]=(s[i]-'0')*k+a[ln];
            k*=10;
        }
    }
    void operator = (const lint &t)
    {
        ln=t.ln;
        memcpy(a,t.a,sizeof(t.a));
    }
    bool operator < (const lint &t) const
    {
        if(ln!=t.ln) return ln<t.ln;
        for(int i=ln;i>=1;i--)
        {
            if(a[i]!=t.a[i])
            {
                return a[i]<t.a[i];
            }
        }
        return 0;
    }
    bool operator > (const lint &t) const
    {
        return t < *this;
    }
    bool operator == (const lint &t) const
    {
        if(ln!=t.ln) return 0;
        for(int i=ln;i>=1;i--)
        {
            if(a[i]!=t.a[i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool operator <= (const lint &t)const
    {
        return !(*this>t);
    }
    bool operator >= (const lint &t)const
    {
        return !(*this<t);
    }
    bool operator != (const lint &t)const
    {
        return !(*this==t);
    }

    lint operator + (lint &t) const
    {
        lint r;
        r.ln=max(ln,t.ln);
        for(int i=1;i<=r.ln;i++)
        {
            r.a[i]+=a[i]+t.a[i];
            r.a[i+1]+=r.a[i]/B;
            r.a[i]%=B;
        }
        if(r.a[r.ln+1]>0) r.ln++;
        return r;
    }
    lint operator - (lint &t) const //Note:只能大数减小数
    {
        lint r=*this;
        for(int i=r.ln;i>=1;i--)
        {
            if(r.a[i]<t.a[i])
            {
                r.a[i]+=B;
                r.a[i+1]-=1;
            }
            r.a[i]=r.a[i]-t.a[i];
        }
        while(r.ln>1&&r.a[r.ln]==0) r.ln--;
        return r;
    }
    lint operator * (lint &t) const
    {
        lint r;
        r.ln=ln+t.ln-1;
        for(int i=1;i<=ln;i++)
        {
            for(int j=1;j<=t.ln;j++)
            {
                r.a[i+j-1]+=a[i]*t.a[j];
            }
        }
        for(int i=1;i<=r.ln;i++)
        {
            if(r.a[i]>B)
            {
                r.a[i+1]+=r.a[i]/B;
                r.a[i]%=B;
            }
        }
        int &l=r.ln;
        while(r.a[l+1])
        {
            l++,r.a[l+1]+=r.a[l]/B,r.a[l]%=B;
        }
        return r;
    }
    lint operator / (ll t) const //Note:lint/ll
    {
        lint r;
        int x=0;
        if(ln==1&&a[1]==0) return 0;
        if(t==0) exit(1);
        for(int i=ln;i>=1;i--)
        {
            r.a[i]=((ll)x*B+a[i])/t;
            x=((ll)x*B+a[i])%t;
        }
        r.ln=ln;
        while(r.a[r.ln]==0&&r.ln>1) r.ln--;
        return r;
    }
    lint operator ^ (ll t) const 
    {
        lint r=1,b=2;
        while(t)
        {
            if(t&1) r=r*b;
            b=b*b;
            t>>=1;
        }
        return r;
    }
    void read()
    {
        char s[53333];
        io.readStr(s);
        *this=s;
    }
    void write()
    {
        int dg=0;
        for(int i=125;i>=1;i--)
        {
            int v=a[i];
            for(int k=1000;k>=1;k/=10)
            {
                dg++;
                io.writeChar(v/k+'0');
                /* if(dg%50==0) io.writeChar('\n'); */
                v%=k;
            }
        }
    }
};

/*大型读优/大整数模板结束*/

int getdig(int n)
{
    int ans=0;
    while(n)
    {
        n/=10;
        ans++;
    }
    return ans;
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int size=100<<20;//40M
    __asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));//提交用这个 
    int p;
    scanf("%d",&p);
    lint q=1;
    lint r=q;
    q=q^p;
    q=q-r;
    int ln=(q.ln-1)*4+getdig(q.a[q.ln]);
    io.writeInt(ln);
    io.writeChar('\n');
    q.write();
    io.flush();
    exit(0);
    return 0;
}
