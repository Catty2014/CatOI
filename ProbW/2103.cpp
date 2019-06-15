//WOJ #2103 多人组舞
//Lang:Cpp
//Mtd:
//Diff:Lv.2

#include <bits/stdc++.h>
using namespace std;

int a[2033333];

int b[2033333];

bool cmp(const int&x,const int&y)
{
    return x>y;
}

int main()
{
    int n;
    long long s;
    scanf("%d %lld",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    long long ans=0;
    int minnum=2033333;int st=0,ed=0;
    do{
        do{
            printf("%d")
            ed++;
            ans=b[ed]-b[st];
        }while(ans<s&&ed<=n);
        if(ed-st<minnum) 
        {
            minnum=ed-st;
        }
        st++;
    }while(ed<=n);
    printf("%d",minnum);
}