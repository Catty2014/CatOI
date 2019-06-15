#include <cstdio>
#include <algorithm>
#include <iostream>

using std::sort;
using std::cin;

#define lbit(x) ((x)&(-x)) 

struct operators{
    int T,Q,K,id,R;
    //Time,Query,Kind,identifier,RightValue
}Op[400233];
int m,n,last=0;
int c[100233],a[100233];

inline void _add(int k,int v)
{
    while(k<=100001)
    {
        c[k]+=v;
        k+=lbit(k);
    }
    return ;
}

inline int qur(int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=c[k];
        k-=lbit(k);
    }
    return ans;
}

void OpAdd(int T,int Q,int K,int id,int R)
{
    last++;
    Op[last].T=T;
    Op[last].Q=Q;
    Op[last].K=K;
    Op[last].id=id;
    Op[last].R=R;
    return ;
}

bool cmp1 (const operators &a,const operators &b)
{
    if(a.K<b.K) return 1;
    if(a.id<b.id) return 1;
    return 0;
}

bool cmp2 (const operators &a,const operators &b)
{
    return (a.id<b.id);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        OpAdd(0,0,a[i],i,0);
    }
    for(int i=1;i<=m;i++)
    {
        // printf("DEBUG!\n");
        char c;
        cin>>c;
        if(c=='C')
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if(a[u]!=v)
            {
                OpAdd(i,1,a[u],u,0);
                OpAdd(i,0,v,v,0);
                a[u]=v;
            }
        }
            else
            {
                int x,y,k;
                scanf("%d %d %d",&x,&y,&k);
                OpAdd(1,2,k,x,y); 
            }
        
    }
    for(int i=1;i<=n;i++)
    {
        OpAdd(m+1,1,a[i],i,i+1);
    }
    sort(Op+1,Op+m+1,cmp1);
    for(int i=1;i<=last;i++)
    {
        if(Op[i].Q==2)
        {
            Op[i].R=qur(Op[i].R)-qur(Op[i].id-1);
        }
        
        else {
            if (Op[i].Q==1)
            {
               _add(Op[i].id,-1);
            }
            else
            {
                _add(Op[i].id,1);
            }
        }
    }
    sort(Op+1,Op+m+1,cmp2);
    for(int i=1;i<=last;i++)
    {
        if(Op[i].Q==2)
        {
            printf("%d\n",Op[i].R);
        }
    }
    return 0;
}