#include <bits/stdc++.h>
using namespace std;
bool a[256];
int main()
{
    a[97]=1;
    int b=0;
    char s[23];
    scanf("%d",&b);
    for(int i='0';i<='9';i++)
    {
        a[i]=1;
    }
    for(int i=1;i<=b;i++)
    {
        scanf("%s",s);
        int p=s[0],q=s[2];
        a[p]=a[q];
        // for(int j='a';j<='z';j++)
        // {
        //     printf("%d ",a[j]);
        // }
    }
    // char p,q,r;
    // for(int i=1;i<=b;i++)
    // {
    //     cin>>p>>q>>r;
    //     a[p]=a[r];
    // }
    bool tmp4;
    for(int i='a';i<='z';i++)
    {
        if(a[i]) {
            printf("%c ",i);
            tmp4=1;
        }
    }
    if(tmp4==0)
    {
        printf("none\n");
    }
    return 0;
}

