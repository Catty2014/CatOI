#include <cstdio>
#include <cstring>

char str[233];
char c;

int main()
{
    int n;
    scanf("%d",&n);
   bool ready=1;
    scanf("%c",&c);
    while(scanf("%c",&c)!=EOF)
    {
        if(c==32) ready=1;
        if(ready==1&&c>=97&&c<=121) {printf("%c",(c-32));ready=0;}
        if(ready==1&&c>=65&&c<=90) {printf("%c",c);ready=0;}
        if(c==10) 
        {
            printf("\n");
            ready=1;
        }
    }
    return 0;
}