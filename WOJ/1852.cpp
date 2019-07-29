#include <cstdio>
#include <algorithm>
#include <cstring>

using std::max;
using std::min;

//typedef unsigned long uint;

int a[233];

bool prm(int n)
{
    if(n==0||n==1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    char s[233];
    scanf("%s",s+1);
    for(uint i=1;i<=strlen(s+1);i++)
    {
        a[s[i]-'a']++;
    }
    std::sort(a+1,a+26,cmp);
    int mmax=a[1];
    int mmin=0;
    for(uint i=1;i<=strlen(s);i++)
    {
        if(a[i]==0) {
            mmin=a[i-1];
            break ;
        }
    }
    if(prm(mmax-mmin))
    {
        printf("Lucky Word\n%d\n",mmax-mmin);
    }
    else
    {
        printf("No Answer\n%d\n",0);
    }
}

//:P
