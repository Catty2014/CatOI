#include <cstdio>

int n;
long long int a[533333];
int k=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long long int p;
        scanf("%lld",&p);
        if(a[k]<p) a[++k]=p;
        else
        {
            while(a[k]>=p)
            {
                k--;
                if(k<0) break;
            }
            a[++k]=p;
        }
        // for(int i=0;i<=100;i++)
        // {
            // printf("%d ",a[i]);
        // }
        printf("%lld ",a[k-1]);
        // printf("\n");
    }
}