#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ind[30];
bool vis[30];
int par[30],ran[30];
void init()
{
    for(int i=0;i<30;i++)
    {
        par[i]=i;
        ran[i]=1;
    }
}
int Find(int x)
{
    if(par[x]!=x) return par[x]=Find(par[x]);
    return x;
}
void Union(int a,int b)
{
    int x=Find(a);
    int y=Find(b);
    if(x==y) return ;
    if(ran[x]>ran[y])
    {
        par[y]=x;
        ran[x]+=ran[y];
    }
    else
    {
        par[x]=y;
        ran[y]+=ran[x];
    }
}
int main()
{
    int t,n;
    char str[1010];
    cin>>t;
    while(t--)
    {
        init();
        memset(ind,0,sizeof(ind));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            int u=str[0]-'a';
            int v=str[len-1]-'a';
            ind[u]--,ind[v]++;
            vis[u]=1,vis[v]=1;
            Union(u,v);
        }
        int sum_par=0;
        for(int i=0;i<30;i++)
          if(vis[i]&&par[i]==i) sum_par++;
        if(sum_par>1)
        {
            puts("The door cannot be opened.");
            continue;
        }
        int zheng=0,fu=0,ling=0;
        for(int i=0;i<30;i++)
        {
            if(ind[i]==0) ling++;
            else if(ind[i]==1) zheng++;
            else if(ind[i]==-1) fu++;
        }
        if(ling==30||(zheng==1&&fu==1&&ling==28))
          puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    return 0;
}

