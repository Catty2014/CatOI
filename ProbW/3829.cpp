#include <cstdio>
#include <cstring>

const int N=233333;//<--If RE,fix here

int tr[N][4];
int tn;
bool ta[N];
char str[N];

bool ins()
{
    // printf("2333333333333333\n");
    int cu=0;
    bool tg=0;
    for(int i=0;str[i]!='\0';i++)
    {
        int nxt=str[i]-'0';
        if(!tr[cu][nxt])
        {
            tg=0;
            tr[cu][nxt]=++tn;
        }
        cu=tr[cu][nxt];
        if(ta[cu]) return 1;
    }
    ta[cu]=1;
    return tg;
}

int main()
{
    bool ac=1;
    int k=1;
    while(scanf("%s",str)!=EOF)
    {
        // printf("%s",str);
        if(str[0]=='9')
        {
            printf("Set %d is ",k++);
            if(!ac) printf("not ");
            printf("immediately decodable\n");
            ac=1;
            memset(str,0,sizeof(str));
            memset(tr,0,sizeof(tr));
            memset(ta,0,sizeof(ta));
            continue;
        }
        if(ac) ac=!ins();
        memset(str,0,sizeof(str));
        // printf("AC=========%d\n",(int)ac);
    }
    return 0;
}