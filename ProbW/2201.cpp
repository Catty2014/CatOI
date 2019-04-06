#include <stdio.h>

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        if(n>=3) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}