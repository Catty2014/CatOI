#include<cstdio>

inline int read()
{
    char ch;
    int ret=0;
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        ret=ret*10+ch-'0';
        ch=getchar();
    }
    return ret;
}

int main()
{
    while(1)
    {
        int p;
        p=read();
        printf("%d\n",p);
    }
    return 0;
}