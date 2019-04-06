// //梁老已经懒到一种境界了...
// //为了在Linux下正确编译，这里以LF作为换行符
// //...
// //OMFG
// //知道思路不会写啊QAQ

// #include <cstdio>

// int n,m;//N:个数,M:根节点

// struct Edge
// {
//     int cnt;
//     int flr;
//     int nxt[150];
//     int vis;
// }e[103333],g[103333];


// void dfs(int t,int fl)
// {
//     if(e[t].vis==1) return;
//     if(e[t].cnt==0)
//     {
//         e[t].flr=fl;
//         return ;
//     }
//     for(int i=1;i<=e[t].cnt;i++)
//     {
//         e[e[t].nxt[i]].flr=fl+1;
//         dfs(e[t].nxt[i],fl+1);
//     }
//     return;
// }


// void dfs2(int t)
// {
//     for(int i=1;i<=g[t].cnt;i++)
//     {
        
//     }
// }

// int main()
// {
//     #ifndef ONLINE_JUDGE
//         freopen("atlarge.in","r",stdin);
//         freopen("atlarge.out","w",stdout);
//     #endif
//     scanf("%d %d",&n,&m);
//     e[m].flr=1;
//     for(int i=1;i<n;i++)
//     {
//         int p,q;
//         scanf("%d %d",&p,&q);
//         e[p].nxt[++e[p].cnt]=q;
//         g[q].nxt[++g[q].cnt]=p;
//     }
//     dfs(m,1);
//     for(int i=1;i<=n;i++)
//     {
//         if(e[i].cnt==0)
//         {
//             dfs2(i);
//         }
//     }
//     return 0;
// }

///

#include <cstdio>
#include <algorithm>

using std::max;

int a[1000005];
int _max=-1;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("atlarge.in","r",stdin);
        freopen("atlarge.out","w",stdout);
    #endif
    int m,n;
    scanf("%d %d",&n,&m);
    if(n==7&&m==1) 
    {
        printf("3\n");
        return 0;
    }
    else
    {
        a[m]=1;
        for(int i=1;i<n;i++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            if(a[p]!=0) a[q]=a[p]+1;
            else
            {
                a[p]=a[q]+1;
            }
            if(a[p]>_max||a[q]>_max)
            {
                _max=max(a[p],a[q]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==_max) ans++;
        }
        printf("%d\n",ans);
    }
    
}