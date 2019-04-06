//SDOJ #1831 Êý×ÖÍ³¼Æ
//C

#include <stdio.h>
int main()
{
    int L,R;
    int n=0,m=0;
    int num=0;
    scanf("%d %d",&L,&R);
    for (int i=L;i<=R;i++)
    {
        num=i;
        while(num)
        {
            m=num%10;
            num=num/10;
            if(m==2) n++;
        }
    }
    printf("%d",n);
    return 0;
}
