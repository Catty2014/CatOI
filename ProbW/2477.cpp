/* LDWOJ #2477 最大子阵
 * Mtd:Dp
 * With whyvev's help
 */

#include<cstdio>

int a[533][533];
int b[533];

int MaxSumSub(int n)
{
//    printf("%d\n",a[1]);
    int sum=0x80000000;int t=0;
    for(int i=1;i<=n;i++)
    {
        if(t>0)
        {
            t+=b[i];
        }
        else
        {
            t=b[i];
        }
        if(t>sum)
        {
            sum=t;
        }
    }
//    printf("%d\n",sum);
    return sum;
}
int MaxSumMain(int n,int m)
{
    int sum=0x80000000;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            b[k]=0;
        }
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                b[k]+=a[j][k];
                
            }   
            int _max=MaxSumSub(m);
                if(_max>sum)
                {
                    sum=_max;
                }
        }
    }
    return sum;
}

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //printf("%d\n",a[1][1]);
    printf("%d\n",MaxSumMain(n,m));
    return 0;
}