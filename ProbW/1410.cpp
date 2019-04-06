/****************************************
 * W1410 括号的匹配
 * Stack
 ****************************************/
#include <cstdio>
#include <cstring>
int stk[2333];
int st;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[2333];
        scanf("%s",s+1);
        for(int i=1;;i++)
        {
            bool val=1;
            if(s[i]=='\0') break;
            switch (s[i])
            {
                case '{':
                    if(stk[st]>1) {val=0;break;}
                    stk[++st]=1;
                    break;
                case '[':
                    if(stk[st]>2) {val=0;break;}
                    stk[++st]=2;
                    break;
                case '(':
                    if(stk[st]>3) {val=0;break;}
                    stk[++st]=3;
                    break;
                case '<':
                    stk[++st]=4;
                    break;
                case '>':
                    if(stk[st]!=4)
                    {
                        val=0;break;
                    }
                    else
                    {
                        st--;
                    }
                    break;
                case ')':
                    if(stk[st]!=3)
                    {
                        val=0;break;
                    }
                    else
                    {
                        st--;
                    }
                    break;
                case ']':
                    if(stk[st]!=2)
                    {
                        val=0;break;
                    }
                    else
                    {
                        st--;
                    }
                    break;
                case '}':
                    if(stk[st]!=1)
                    {
                        val=0;break;
                    }
                    else
                    {
                        st--;
                    }
                default:
                    break;
            }
            if(val==0) 
            {
                st=2333;
                break;
            }
        }
        if(st==0) printf("YES\n");
        else printf("NO\n");
        st=0;
        memset(stk,0,sizeof(stk));
    }
}