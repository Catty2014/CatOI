#include <cstdio>
#include <iostream>
#include <algorithm>

using std::sort;

int n,k;
int a[264],b[264];

char p[264];
int q[264];
char s[264];
bool vi[264];
char x[264];

void dfs(int t,int k)
{
    s[k]=p[t];
    b[a[t]]=0;
    if(k==n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vi[i]==0 && b[i]==0)
        {
            vi[i]=1;
            dfs(i,k+1);
            vi[i]=0;
        }
    }
    b[a[t]]=t;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("place.in","r",stdin);
        freopen("place.out","w",stdout);
    #endif
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        std::cin>>x[i];
        // q[(int)c]=i;
        // p[i]=(int)c;
    }
    sort(x+1,x+n+1);
    // for(int i=1;i<=n;i++)
    // {
        // printf("%d %c\n",x[i],x[i]);
    // }
    for(int i=1;i<=n;i++)
    {
        q[(int)x[i]]=i;
        p[i]=(int)x[i];
    }
    for(int i=1;i<=k;i++)
    {
        char tm[64],tn[64];
        scanf("%s %s",tm,tn);
        char r=tm[0],t=tn[0];
        a[q[r]]=q[t];
        b[q[t]]=q[r];
        // printf("%d %d %d %d\n",a[r],q[t],b[t],q[r]);
    } 
    for(int i=1;i<=n;i++)
    {
        vi[i]=1;
        if(b[i]==0) dfs(i,1);
        vi[i]=0;
    }
    return 0;
}