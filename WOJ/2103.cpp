//WOJ #2103 多人组舞
//Lang:Cpp
//Mtd:
//Diff:Lv.2

#include <bits/stdc++.h>
using namespace std;

long long a[5033333];

long long b[5033333];


int main()
{
    int n;
    long long s;
    scanf("%d %lld",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i];
        //printf("%d\n",b[i]);
    }
    long long ans=0;
    long long minnum=2147483600;
    int st=0,ed=1;
    while(ed<=n+1)
    {
        do
        {
            /* printf("%d %d\n",st,ed); */
            ed++;
            ans=b[ed]-b[st-1];
            if(ans>=s) break;
        }while(ed<=n);
        do
        {
            st++;
            ans=b[ed]-b[st-1];
            if(ans<s) 
            {
                st--;
                break;
            }
        }while(ans>=n&&st<=ed);
        /* printf(">%d %d\n",st,ed); */
        if(ed-st+1<minnum)
        {
            minnum=ed-st+1;
            /* printf(">%d %d\n",st,ed); */
        }
    }
    printf("%lld",minnum);
}
