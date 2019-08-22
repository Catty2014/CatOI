#include <cstdio>

int main()
{
    int n,a;
    scanf("%d %d",&n,&a);
    n--;
    while(n--)
    {
        int t;
        scanf("%d",&t);
        a^=t;
    }
    printf("%s\n",(a)?"win":"lose");
}
