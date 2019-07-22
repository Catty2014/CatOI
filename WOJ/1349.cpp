#include <bits/stdc++.h>
using namespace std;

int a[133][133];
int f[133];
int n;
int k=1;
int x[133]={0};

int gettime(int pl)
{
    if(pl==n) {
        return 0;  
    }
    int min_time=233333333;
    for(int i=1;i<=n;i++)
    {
        if(a[pl][i]!=0)
        {
            f[pl]=a[pl][i]+gettime(i);
            //printf("f[%d]=%d a[%d][%d]=%d\n",pl,f[pl],pl,i,a[pl][i]);
            if(f[pl]<min_time) {
            min_time=f[pl];
            x[pl]=i;
            }
        }
    }
    if(min_time!=233333333) return min_time;
    return 0;
}

void showway(int k)
{   if(k==n) return;
    printf("%d ",x[k]);
    showway(x[k]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("minlong=%d\n1 ",gettime(1));
    showway(1);
    return 0;
}