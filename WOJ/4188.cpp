#include <cstdio>
#include <cstring>

char s[666];
int stk[20][20];
int stkPointer[20];//stack pointer
int stkType[20];
int stkCurrent=1;

int main()
{
    scanf("%s",s);
    int ln=strlen(s);
    int num=0;
    for(int i=1;i<=ln;i++)
    {
        if(s[i]=='(')
        {
            stkCurrent++;
            stkType[stkCurrent]=2;
        }
        if(s[i])
    }
}
