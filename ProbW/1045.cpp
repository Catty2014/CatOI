/*
ID:18111431
TASK:beads
LANG:C++
*/

#include <bits/stdc++.h> //Code of Pig2014
using namespace std;//Contact me:18111431031@163.com
#define debug(x) printf("var=%d\n",x)//Language:Cpp
typedef long long ll;
const int MOD=1e9+7;

char x[800];

int n;
int dfs(int p)
{
    int s1=0,s2=0,s3=0,s4=0;
    int tg1=0,tg2=0,tg3=0,tg4=0;
    for(int i=p;i<=2*n;i++)
    {
        if(s2==0&&x[i]=='w') tg2++;
        if(x[i]==x[p]||x[i]=='w') tg2++,s2++;
        if(x[i]!=x[p]) break;
    }
    for(int i=p-1;i>=0;i--)
    {
        if(s1==0&&x[i]=='w') tg1++;
        if(x[i]==x[p]||x[i]=='w') tg1++,s1++;
        if(x[i]!=x[p]) break;
    }
    for(int i=p+tg2;i<=2*n;i++)
    {
        if(s3==0&&x[i]=='w') tg3++;
        if(x[p+tg2]==x[i]||x[i]=='w') tg3++,s3++;
        else break;
    }
    for(int i=p-tg1-1;i>=0;i--)
    {
        if(s4==0&&x[i]=='w') tg4++;
        if(x[p-tg1-1]==x[i]||x[i]=='w') tg4++,s4++;
        else break;
    }
    return max(tg2+tg1+tg3,tg2+tg1+tg4);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    #endif

    scanf("%d",&n);
    scanf("%s",x+1);
    /* for(int i=1;i<=2*n+2;i++) */
    /* { */
        /* printf("x[%d]=%c ",i,x[i]); */
    /* } */
    /* printf("\n"); */
    x[2*n+1]=x[n+1];
    for(int i=n+1;i<=2*n;i++)
    {
        x[i]=x[i-n];
    }
    /* for(int i=1;i<=2*n+2;i++) */
    /* { */
    /*     printf("x[%d]=%c ",i,x[i]); */
    /* } */
    /* printf("\n"); */
    int max=-1;
    for(int i=1;i<=2*n;i++)
    {
        int tmp=dfs(i);
        /* printf("dfs(%d)=%d\n",i,tmp); */
        if(max<tmp) max=tmp;
    }
    printf("%d\n",max);
    return 0;
}

