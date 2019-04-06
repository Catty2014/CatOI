#include <bits/stdc++.h>
using namespace std;

int a[133333];
int k;

void nummake(int num)
{
    //printf("Start:%d\n",num);
    long long tmp1=num;
    tmp1*=num;
    int ans=0;
    int t=1;
    do{
        int tmp2=tmp1%10;
        tmp1/=10;
        ans=t*tmp2+ans;
        //printf("t=%d ans=%d\n",t,ans);
        t*=10;
        if(ans==num) {
            a[k++]=num;
            break;
    }}
    while(tmp1!=0);
    tmp1=0;ans=0;
    if(num>=100000) return;
    else
    nummake(num+1);
    return;
}

int main()
{
    nummake(1);
    int l,r;
    scanf("%d %d",&l,&r);
    for(int i=1;i<=100000;i++)
    {
        if(a[i]>r) break;
        if(a[i]>=l) printf("%d\n",a[i]);
        //printf("Expected=%d\n",a[i]);
    }
    return 0;
}

