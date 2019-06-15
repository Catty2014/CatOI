//SDOJ #1179 女仆酱的求助
//LibName:HelpOfServant
//Diff:Lv.5
//Mtd:MakeSheet
//Lang:Cpp

/*TRIAL VERSION*/

#include <bits/stdc++.h>
using namespace std;

int a[20000000];
int tgd=0;
int k=0;

struct numarea{
    long long st,ed;
}n[13];

void nummake(int num,int dig)
{
    if(dig==tgd) return;
    for(int i=1;i<=9;i++)
    {
        num*=10;
        num+=i;
        if(num%i==0) a[k++]=num;
        nummake(num,dig+1);
        num/=10;
    }
}

void getdig(int ed)
{
    tgd=0;
    do{
    ed/=10;
    tgd++;
    }while(ed!=0);
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&n[i].st,&n[i].ed);
        getdig(n[i].ed);
    }
    nummake(0,0);
    sort(a+1,a+k+1);
    for(int i=1;i<=t;i++)
    {
        for(int j=1;;j++)
        {
            
        }
    }
}
