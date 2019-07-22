#include <bits/stdc++.h>
using namespace std;

struct toys{
    string name;
    int place;
    bool face;
}a[2333];

struct cmds{
    int face;
    int step;
}b[2333];

int targ=1;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].face>>a[i].name;
        a[i].place=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&b[i].face,&b[i].step);
        if((a[targ].face^b[i].face)==0)
        {
            targ-=b[i].step;
            if(targ<=0) targ+=n;
        }
        else 
        {
            targ+=b[i].step;
            if(targ>n) targ-=n;
        }
    }
    cout<<a[targ].name<<endl;
    return 0;
}
