#include <cstdio>

#define min(a,b) ((a<b)?a:b)

int p;
int a[1000233];
int b[1023333];
int dig=1;

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d",&p);
    a[1]=1;
    while(p--)
    {   
        for(int i=1;i<=dig;i++)
        {
            a[i]*=2;
            if(i==dig&&a[i]>=10) dig++;
            a[i]+=b[i];
            b[i]=0;
            b[i+1]=a[i]/10;
            a[i]%=10;
        }
    }
    a[1]-=1;
    int k=1;
    while(a[k]==-1)
    {
        a[k]=9;
        a[k+1]--;
        k++;
    }
    printf("%d\n",dig);
    int op=0;
    if(dig<500)
    {
        for(int i=dig;i<500;i++)
        {
            printf("0");
            op++;
            if(op==50)
            {
                printf("\n");
                op=0;
            }
        }
    }
    for(int i=min(500,dig);i>=1;i--)
    {
        printf("%d",a[i]);
        op++;
        if(op==50)
        {
            printf("\n");
            op=0;
        }
    }
    return 0;
}
