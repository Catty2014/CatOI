/*
ID: 18111431
LANG: C++
TASK: gift1
*/

#include <cstdio>
#include <cstring>

const int MOD=191563;
const int p=26;
char nm[20][20];
int a[200233];
int b[12];

#define ch(c) (c-'a')

int HASH(char c[])
{
    int ans=0;
    int ln=strlen(c);
    for(int i=0;i<ln;i++)
    {
        ans+=ans*p+ch(c[i])%MOD;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("gift1.in","r",stdin);
        freopen("gift1.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",nm[i]);
        a[HASH(nm[i])]=i;
    }
    for(int i=1;i<=n;i++)
    {
        char ch[23];
        scanf("%s",ch);

    }
}
