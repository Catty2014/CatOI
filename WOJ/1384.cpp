#include<stdio.h>
using namespace std;

int a[6][6];

int main()
{
    int p;
    scanf("%d",&p);
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=6;i++)
    {
        a[i][i]+=p;
        a[i][7-i]+=p;
    }
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}