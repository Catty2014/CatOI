#include <cstdio>
#include <queue>
#include <cstring>

const int M=233333;
const int N=2333;

struct Edge
{
    int v,w,n;
};

Edge e[N];
int f[N],eCnt;

void edgeAdd(int u,int v,int w)
{
    eCnt++;
    e[eCnt].v=v;
    e[eCnt].w=w;
    e[eCnt].n=f[u];
    f[u]=eCnt;
}

int val[N];
int num[N];
int cnt[N];
int dis[N];
int vi[N];

class Queue
{
private:
    int l,r,a[M];
public:
    void clr()
    {
        l=0;r=1;
    }
    void push(int x)
    {
        a[r]=x;
        r=(r+1)%M;
    }
    bool empty()
    {
        return ((l+1)%M==r);
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

int spfa()
{
    /* std::queue<int>q; */
    Queue q;
    q.clr();
    for(int i=0;i<=24;i++)
    {
        q.push(i);
        cnt[i]=1;
        dis[i]=0;
        vi[i]=1;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vi[u]=0;
        for(int i=f[u];~i;i=e[i].n)
        {
            int v=e[i].v;
            int w=e[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vi[v])
                {
                    vi[v]=1;
                    q.push(v);
                    if(++cnt[v]>25)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(f,-1,sizeof(f));
        eCnt=0;
        for(int i=1;i<=24;i++)
        {
            scanf("%d",&val[i]);
        }
        int m;
        scanf("%d",&m);
        memset(num,0,sizeof(num));
        for(int i=1;i<=m;i++)
        {
            int c;
            scanf("%d",&c);
            num[c+1]++;
        }
        int lb=-1,rb=m+1;
        while(rb-lb>1)
        {
            int mid=(lb+rb)/2;
            memset(f,-1,sizeof(f));
            eCnt=0;
            for(int i=1;i<=24;i++)
            {
                edgeAdd(i-1,i,0);
                edgeAdd(i,i-1,-num[i]);
                if(i>=8)
                {
                    edgeAdd(i-8,i,val[i]);
                }
                else
                {
                    edgeAdd(i+16,i,val[i]-mid);
                }
            }
            edgeAdd(0,24,mid);
            edgeAdd(24,0,-mid);
            if(spfa())
            {
                rb=mid;
            }
            else
            {
                lb=mid;
            }
        }
        if(rb==m+1)
        {
            printf("No Solution\n");
        }
        else
        {
            printf("%d\n",rb);
        }
    }
    return 0;
}
