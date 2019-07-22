#include <cstdio>
#include <iostream>

using std::cin;

#define lbit(x) ((x)&(-x))
int n,m;
int c[2333][2333];

inline void _add (int x,int y,int v)
{
    int _y=y;
    while(x<=n)
    {
        y=_y;
        while(y<=m)
        {
            c[x][y]+=v;
            y+=lbit(y);
        }
        x+=lbit(x);
    }
    return ;
}

inline int qur (int x,int y)
{
    int ans=0,_y=y;
    while(x>0)
    {
        y=_y;
        while(y>0)
        {
            ans+=c[x][y];
            y-=lbit(y);
        }
        x-=lbit(x);
    }
    return ans;
}

int main()
{
    int Q;
    scanf("%d %d %d",&n,&m,&Q);
    while(Q--)
    {
        char OP;
        cin>>OP;
        if(OP=='C')
        {
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v);
            _add(x,y,v);
        }
        if(OP=='Q')
        {
            int _x1,_x2,_y1,_y2;
            scanf("%d %d %d %d",&_x1,&_y1,&_x2,&_y2);
            int ans=qur(_x1-1,_y1-1)+qur(_x2,_y2)-qur(_x1-1,_y2)-qur(_x2,_y1-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}