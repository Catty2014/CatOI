#include <cstdio>
#include <algorithm>

#define db printf
#define MAX 40001

struct cow
{
    int x;int y;int dist;
}c[50023];

long long midx,midy;

bool cmp(const cow&a,const cow&b)
{
    if(a.dist<b.dist) return 1;
    if(a.x<b.x) return 0;
    if(a.y<b.y) return 0;
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("reduceb.in","r",stdin);
    freopen("reduceb.out","w",stdout);
    #endif
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d",&c[i].x,&c[i].y);
        midx=(midx+c[i].x)/2;
        midy=(midy+c[i].y)/2;
    }
    for(int i=1;i<=N;i++)
    {
        c[i].dist=(c[i].x-midx)*(c[i].x-midx)+(c[i].y-midy)*(c[i].y-midy);
    }
    std::sort(c+1,c+N+1,cmp);
    // int ansx=0,ansy=0;
    int maxx=0,maxy=0,minx=MAX,miny=MAX;
    for(int i=1;i<=N-3;i++)
    {
        //db("%d:%d %d %d\n",i,c[i].x,c[i].y,c[i].dist);
        if(c[i].x<minx) minx=c[i].x;
        if(c[i].y<miny) miny=c[i].y;
        if(c[i].x>maxx) maxx=c[i].x;
        if(c[i].y>maxy) maxy=c[i].y;
    }
    //db("%d %d %d %d\n",minx,miny,maxx,maxy);
    printf("%d\n",((maxx-minx)*(maxy-miny)));
    return 0;
}