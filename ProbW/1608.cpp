#include <cstdio>
#include <cstring>

typedef long long ll;

#define minc (y/x +1)
#define MAX(a,b) ((a>b)?(a):(b))

int tmp[533],ans[533];//500Enough
int fi,x,y;

int _g(int p,int q)
{
    return (p%q)?(_g(q,p%q)):(q);
}

bool cmp(int d)
{
    for(int i=d;i>=0;i--)
    {
        if(tmp[i]!=ans[i])
        {
            return (bool)(ans[i]==-1 || tmp[i]<ans[i]);
        }
    }
    return false;
}

bool dfs(int lim,int d,int f,ll x,ll y)
{
    if(d==lim) //Target
    {
        if((y%x)) return false;
        tmp[d]=y/x;
        if(cmp(d)) memcpy(ans,tmp,sizeof(ans));
        return true;
    }
    bool val=false;
    f=MAX(f,minc);
    int i=f;
    while(1)
    {
        if(y*(lim+1-d)<=i*x) break;
        tmp[d]=i;
        ll _y1=y*i;
        ll _x1=x*i-y;
        ll G=_g(_x1,_y1);
        if(dfs(lim,d+1,i+1,_x1/G,_y1/G)) val=true;
        i++;
    }
    return val;
}

int main()
{
    scanf("%d %d",&x,&y);
    int d=1;
    fi=minc;
    while(1)
    {
        memset(ans,-1,sizeof(ans));
        if(dfs(d,0,fi,x,y)) break;
        d++;
    }
    for(int i=0;i<=d;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}