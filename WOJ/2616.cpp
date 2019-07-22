//  High Accuracy Algorithm
// Working...
// /*
#include <cstdio>
#include <cmath>

using std::sqrt;

int a[2333];
int p[2333];
int s[2333];

int main()
{
    int num=0;
    int i=0;
    while(scanf("%1d",&num)!=EOF)
    {
        a[++i]=num;
    }
    int k=0;
    for(int j=i;j>=1;j-=2)
    {
        p[++k]=a[j-1]*10+a[j];
    }
    int t=0;
    int nn=0;
    s[++t]=(int)sqrt(p[k]);
    for(int j=k-1;j>=1;j--)
    {
        nn=nn*100+p[j];

        nn-=
    }
}
// */
