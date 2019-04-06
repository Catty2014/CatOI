#include <bits/stdc++.h>
using namespace std;

int x[400],f[400],n,st,ed;

struct Elev{
    int id,stp;
};

int bfs(int s){
    queue<Elev>q;
    q.push((Elev){s,0});f[s]=1;
    while(!q.empty())
    {
        Elev t=q.front();q.pop();
        if(t.id==ed)return t.stp;
        int nxt=t.id+x[t.id];
        if(nxt<=n && f[nxt]==0)
        {
            q.push((Elev){nxt,t.stp+1});
            f[nxt]=1;
        }
        nxt=t.id-x[t.id];
        if(nxt>0 && f[nxt]==0)
        {
            q.push((Elev){nxt,t.stp+1});
            f[nxt]=1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d",&n,&st,&ed);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }
    int ans=bfs(st);
    printf("%d\n",ans);
    return 0;
}

