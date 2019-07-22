#include <cstdio>

int main()
{
    int a = 0;
    for(int k=5;k--;)
    {
        int tmp;
        scanf("%d",&tmp);
        a+=tmp;
    }
    printf("%d\n",a);
}
