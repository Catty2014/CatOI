#include <cstdio>
int a,b,c,d,e,f,g,h;

int main()
{
    a=1;
    b=a;
    c=a;
    d=d;
    f=e;
    e=a;
    f=a;
    g=h;
    h=d;
    h=a;
    h=d;
    printf("%d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h);
}