#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

int a[2333],into[2333],Map[1333][1333],n;

bool tpsrt()
{
    for(int i=1;i<=n;i++)
    {
        int j=1;
        while(into[j]!=0&&j<=n)
        {
            j++;
        }
        if(j>n)
        {
            return false;
        }
        else
        {
            a[i]=j;
            into[j]=0x23333333;
            for(int k=1;k<=n;k++)
            {
                if(Map[j][k]!=0) into[k]--;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    int i,j;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        Map[i][j]=1;
        into[j]++;
    }
    if(tpsrt())
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    else
    {
        printf("No answer\n");
    }
    return 0;
}

