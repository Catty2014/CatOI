/* Test181230-T1 Reduce
 * VIOLENCE?!!!!
 * STD
 */

#include <cstdio>
#include <algorithm>

using std::sort,std::min;

struct cow
{
    int x,y,a;
}a[51333],b[51333],c[51333];


void solve (int x)
{
    int tmp=0,p=0;
    for(int i=1;i<=k;i++)if(x!=i)a[++p]=c[i];   
    sort(a+1,a+p+1,cmp1);
    tmp=a[p].x-a[1].x;
    sort(a+1,a+p+1,cmp2);
    tmp*=a[p].y-a[1].y;
    ans=min(ans,tmp);
    return ;
}