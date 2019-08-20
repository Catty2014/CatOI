#include <cstdio>
#include <algorithm>
#include <cstring>

const int N=100233;
const int M=823333;
const int I=0x73333333;

int n,m;
int a[N];

struct Edge
{
    int t,n;
};
int eCnt1,eCnt2;
Edge ea[M],eb[M];
int f1[M],f2[M];

void edgeAdd1(int u,int v)
{
    eCnt1++;
    ea[eCnt1].t=v;
    ea[eCnt1].n=f1[u];
    f1[u]=eCnt1;
}

void edgeAdd2(int u,int v)
{
    eCnt2++;
    eb[eCnt2].t=v;
    eb[eCnt2].n=f2[u];
    f2[u]=eCnt2;
}

class Queue
{
private:
    int l,r,a[M];
public:
    void clr()
    {
        l=0;r=1;
    }
    bool empty()
    {
        return ((l+1)%M==r);
    }
    void push(int x)
    {
        a[r]=x;
        r=(r+1)%M;
    }
    void pop()
    {
        l=(l+1)%M;
    }
    int front()
    {
        return a[(l+1)%M];
    }
};

int d1[N],d2[N],v1[N],v2[N];

void spfa()
{
    Queue q;
    q.clr();
    memset(d1,0xff,sizeof(d1));
    q.push(1);
    v1[1]=1;
    d1[1]=a[1];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        v1[u]=0;
        for(int i=f1[u];i;i=ea[i].n)
        {
            if(d1[u]<d1[ea[i].t] || a[ea[i].t]<d1[ea[i].t])
            {
                d1[ea[i].t]=std::min(d1[u],a[ea[i].t]);
                if(!v1[ea[i].t])
                {
                    v1[ea[i].t]=1;
                    q.push(ea[i].t);
                }
            }
        }
    }
}

void spfb()
{
    Queue q;
    q.clr();
    memset(d2,0xff,sizeof(d2));
    q.push(n);
    v2[n]=1;
    d2[n]=a[n];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        v2[u]=0;
        for(int i=f2[u];i;i=eb[i].n)
        {
            if(d2[u]>d2[eb[i].t] || a[eb[i].t]>d2[eb[i].t])
            {
                d2[eb[i].t]=std::max(d2[u],a[eb[i].t]);
                if(!v1[eb[i].t])
                {
                    v1[eb[i].t]=1;
                    q.push(eb[i].t);
                }
            }
        }
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int ans=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        if(w==1)
        {
            edgeAdd1(u,v);
            edgeAdd2(v,u);
        }
        if(w==2)
        {
            edgeAdd1(u,v);
            edgeAdd1(v,u);
            edgeAdd2(u,v);
            edgeAdd2(v,u);
        }
    }
    spfa();spfb();
    for(int i=1;i<=n;i++)
    {
        ans=std::max(ans,d2[i]-d1[i]);
    }
    printf("%d\n",ans);
    return 0x00;
}
