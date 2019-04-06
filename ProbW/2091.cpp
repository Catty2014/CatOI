#include <bits/stdc++.h>
using namespace std;
#define N 133
#define INF 0x3f7f7f7f
double s[1001][1001]={{0}};
int n,m;
int x[N],y[N];
double dist[N];
int visited[N]={0};

void dijk(int st)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[st]=0;
    int x;
    for(int i=1;i<=n;i++)
    {
        int mnst=INF;
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0&&dist[j]<mnst)
            {
                mnst=dist[j];
                x=j;
            }
        }
        visited[x]=1;
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0&&s[x][j]<INF&&dist[j]>dist[x]+s[x][j])
            {
                dist[j]=dist[x]+s[x][j];
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            s[i][j]=INF;
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        s[a][b]=s[b][a]=sqrt(double(pow(x[a]-x[b],2))+double(pow(y[a]-y[b],2)));
    }
    int st,ed;
    scanf("%d %d",&st,&ed);
    dijk(st);
    printf("%.2lf",dist[ed]);
    return 0;
}

