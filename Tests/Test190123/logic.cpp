//violence~
//VIOLENCE~

#include <cstdio>

struct Node
{
    int nxt[555];
    int cnt;
    int vis;
}e[555];

int ans;
int m,n;

void dfs(int t,int m)
{
    // printf("%d %d\n",t,m);
//    if(e[t].vis==1) return m;
//    if(e[t].cnt==0) return 0;
//    int ret=0;
//    e[t].vis=1;
//    for(int i=1;i<=e[t].cnt;i++)
//    {
//        ret+=dfs(e[t].nxt[i],m+1);
//    } 

//    return ret;
    if(e[t].vis==1) {
        if(m-1==2) m--;
        ans+=m-1;
        return;
    }
    e[t].vis=1;
    for(int i=1;i<=e[t].cnt;i++)
    {   
        if(e[t].nxt[i]==t) continue;
        dfs(e[t].nxt[i],m+1);
    }
    return;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("logic.in","r",stdin);
    freopen("logic.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        e[p].nxt[++e[p].cnt]=q;
    }

    for(int i=1;i<=n;i++)
    {
        // printf("%d\n",i);
        dfs(i,1);
        // if(tmp<=2&&tmp>0) tmp--;
        // ans+=tmp;
        // printf("%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}