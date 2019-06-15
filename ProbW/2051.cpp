//WOJ #2051 猴子选大王
//Lang:Cpp
//Diff:Lv.2
//Mtd:Emulate

#include <bits/stdc++.h>
using namespace std;

int a[233333];

int num;

int n;

void ltr()
{
    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1) {
            continue;
        }
        a[i]=k++%3;
        if(a[i]==0)
        {
            a[i]=-1;
            num--;
        }
    }
    /* for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);.cpp
    } */
}

void rtl()
{
    int k=1;
    for(int i=n;i>=1;i--)
    {
        //printf("num=%d\n",num);
        if(a[i]==-1) {
            continue;
        }
        a[i]=k++%3;
        if(a[i]==0)
        {
            a[i]=-1;
            num--;
        }
    }
    /* for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    } */
}

void lj()
{
    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1) {
            continue;
        }
        printf("%d\n",i);
        return;
    }
}

void rj()
{
    int k=1;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==-1) {
            continue;
        }
        printf("%d\n",i);
        return;
    }
}

void Go()
{
    /* printf("%d\n",num); */
    ltr();
    if(num==2) {rj();return;}
    rtl();
    if(num==2) {lj();return;}
    Go();
}

int main()
{
    /* freopen("test.txt","w",stdout); */
    scanf("%d",&n);
    num=n;
    Go();
    return 0;
}