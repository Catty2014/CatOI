/* WOJ #2122 [模板]电话簿
 * Trie[Template]
 * Self
 * 0/100
 */

#include <cstdio>
#include <cstring>

#define NXT (x[i]-'0')
#define MS(a) memset(a,0,sizeof(a));

int phone[523333][11],tg;
bool end[523333];

bool ins(char x[]) //To big to use integer
{
    int len_x=strlen(x);
    int crt=0;
    bool AMD_YES=1;
    for(int i=0;i<len_x;i++)
    {
        if(!phone[crt][NXT]) //NEW
        {
            AMD_YES=0;
            phone[crt][NXT]=++tg;
        }
        crt=phone[crt][NXT];
        if(end[crt]) //Passed An End Of A Number String
        {
            return 1;
        }
    }
    end[crt]=1;  //Mark
    return AMD_YES;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        MS(phone[0]);
        MS(end);
        tg=0;
        int N;
        bool AMD=1;
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            char p[523333];
            scanf("%s",p);
            if(AMD==1)
            {
                AMD=ins(p);
            }
            //printf("AMD=%d\n",AMD);
        }
        if(AMD==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
