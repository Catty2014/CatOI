//WOJ #2661 足球联赛
//Language:Cpp
//Mtd:
//Diff:Lv.2

#include <bits/stdc++.h>
using namespace std;

struct football{
    int score;
    int id;
}a[100];

bool cmp(const football&x,const football&y)
{
    return x.score>y.score;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        for(int j=1;j<=n;j++)
        {
            //printf("%d %d\n",i,j);
            char t;
            cin>>t;
            if(t=='W') a[i].score+=3;
            if(t=='D') 
            {
                a[i].score+=1;
                a[j].score+=1;
            }
            if(t=='L') a[j].score+=3;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        printf("a[%d].score=%d,id=%d\n",i,a[i].score,a[i].id);
    }*/
    sort(a+1,a+n+1,cmp);
    printf("%d",a[1].id);
    int k=2;
    while(a[k].score==a[1].score)
    {
        printf(" %d",a[k].id);
        k++;
    }
    return 0;
}