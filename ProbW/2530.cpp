#include <cstdio>

#define MAX(a,b) ((a>b)?a:b)

int a[133],d[133][4],f[133][133];
int n;
int q;

int Ap(int i,int j)
{
    if(j==0||i==0) return 0;
    if((d[i][0]==0)&&(d[i][1]==0)) return a[i];
    if(f[i][j]>0) return d[i][j];
    for(int k=0;k<=j-1;k++)
    {
        f[i][j]=MAX((f[i][j]), (Ap(d[i][0],k)+Ap(d[i][1],j-k-1)+a[i]) );
    }
    return d[i][j];
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n-1;i++)
    {
        // a[]
    }
}