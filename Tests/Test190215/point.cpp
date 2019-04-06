#include <cstdio>
#include <algorithm>

using std::sort;

struct point
{
    int x;
    int y;//NOTICE:(-20000)~(+20000)
}p[1333];

int t[7300][7300];

int n;
int ans=0;

bool cmp(const point &a,const point &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("point.in","r",stdin);
        freopen("point.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int _x,_y;
        scanf("%d %d",&_x,&_y);
        p[i].x=_x;
        p[i].y=_y;
        t[_x][_y]++;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int a=p[i].x;
        int b=p[i].y;
        for(int j=1;j<=n;j++)
        {
            if(p[j].x>p[i].x||p[j].y<=p[i].y) continue;
            int c=p[j].x;
            int d=p[j].y;
            ans+=t[c+d-b][d+c-a]*t[a+d-b][b+c-a];
        }
    }
    printf("%d\n",ans);
    return 0;
}