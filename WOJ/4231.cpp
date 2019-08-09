//Gugugu...
//
#include <cstdio>

int main()
{
    int ans = 0;
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c!=10&&c!=32)
            ans++;
    }
    printf("%d\n",ans);
}
