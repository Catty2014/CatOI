//WOJ #1592 生活大爆炸版石头剪刀布
//Diff:Lv.3
//Mtd:Emulate
//Lang:Cpp

#include <bits/stdc++.h>
using namespace std;

int a[233],b[233];

int ansa,ansb;

void judger(int x,int y)
{
    switch(x)
    {
        case 0:
        switch(y)
        {
            case 0:
                return;
            case 1:
                ansb++;
                return;
            case 2:
                ansa++;
                return;
            case 3:
                ansa++;
                return;
            case 4:
                ansb++;
                return;
        }
        case 1:
        switch(y)
        {
            case 0:
                ansa++;
                return;
            case 1:
                return;
            case 2:
                ansb++;
                return;
            case 3:
                ansa++;
                return;
            case 4:
                ansb++;
                return;
        }
        case 2:
        switch(y)
        {
            case 0:
                ansb++;
                return;
            case 1:
                ansa++;
                return;
            case 2:
                //ansb++;
                return;
            case 3:
                ansb++;
                return;
            case 4:
                ansa++;
                return;
        }
        case 3:
        switch(y)
        {
            case 0:
                ansb++;
                return;
            case 1:
                ansb++;
                return;
            case 2:
                ansa++;
                return;
            case 3:
                //ansb++;
                return;
            case 4:
                ansa++;
                return;
        }
        case 4:
        switch(y)
        {
            case 0:
                ansa++;
                return;
            case 1:
                ansa++;
                return;
            case 2:
                ansb++;
                return;
            case 3:
                ansb++;
                return;
            case 4:
                //ansa++;
                return;
        }
    }
}

int main()
{
    int n,na,nb;
    scanf("%d %d %d",&n,&na,&nb);
    for(int i=0;i<=na-1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=nb-1;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<=n-1;i++)
    {
        judger(a[i%na],b[i%nb]);
        //printf("i=%d %d %d %d %d\n",i,i%na,i%nb,ansa,ansb);
    }
    printf("%d %d",ansa,ansb);
    return 0;
}