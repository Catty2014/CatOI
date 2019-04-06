//SDOJ #1801 计数问题
//C

#include <stdio.h>
int main()
{
    int R;
    int n=0,m=0,k=0;
    int num=0;
    scanf("%d %d",&R,&k);
    for (int i=1;i<=R;i++)
    {
        num=i;
        while(num)
        {
            m=num%10;
            num=num/10;
            if(m==k) n++;
        }
    }
    printf("%d",n);
    return 0;
}
