#include <bits/stdc++.h>
using namespace std;
#define N 10086

struct Heat{
    int u,v,w;
}e[N<<1];

int dis[N];
int t,c,ts,te;

void buff(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    for(int i=1;i<t;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(dis[e[j].u]+e[j].w<dis[e[j].v])
            {
                dis[e[j].v]=dis[e[j].u]+e[j].w;
            }
            if(dis[e[j].v]+e[j].w<dis[e[j].u])
            {
                dis[e[j].u]=dis[e[j].v]+e[j].w;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d",&t,&c,&ts,&te);
    for(int i=1;i<=c;i++)
    {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    }
    buff(ts);
    printf("%d",dis[te]);
    return 0;
}
