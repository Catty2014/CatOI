#include <cstdio>
#include <algorithm>

int n,q;
int cnt;
int p[200666];
int cnt2;


struct Tree
{
    int cnt;
    int nxt[133];
    int dfss;
    int tm;
}a[100233];

void dfs(int t,int step)
{
    // printf("%d %d\n",t,step);
    a[t].dfss=step;
    if(a[t].tm!=0) a[t].tm=(++cnt);
    p[++cnt2]=t;
    if(a[t].cnt==0 ) return ;
    for(int i=1;i<=a[t].cnt;i++)
    {
        dfs(a[t].nxt[i],step+1);
        p[++cnt2]=t;
    }
    // p[++cnt2]=t;
    return ;
}

inline int read(){//整数读入优化 
    int x=0,f=1;
    char ch;
    for(ch=getchar();(ch<'0'||ch>'9') && ch!='-';ch=getchar());
    if(ch=='-') {     f=-1;       ch=getchar();   }
    while(ch>='0' && ch<='9') {
        x=(x<<3)+(x<<1)+ch-'0';ch=getchar();
    }//i=i*10+c-'0'
    return x*f;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int p,q;
        //scanf("%d %d",&p,&q);
        p=read();q=read();
        a[p].nxt[++a[p].cnt]=q;
        // a[q].nxt[++a[q].cnt]=p;
    }
    dfs(1,1);
    // for(int i=1;i<=cnt2;i++)
    // {
    //     printf("%d ",p[i]);
    // }
    // printf("\n");
    // for(int i=1;i<=cnt2;i++)
    // {
    //     printf("%d ",a[p[i]].dfss);
    // }
    // printf("\n");
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int m,n;
        int _l=0,_r=0;
        m=read();n=read();
        for(int i=1;i<=cnt2;i++)
        {
            if(p[i]==m&&_l==0) _l=i;
            if(p[i]==n) _r=i; 
        }
        // printf("%d %d\n",_l,_r);
        if(_l>_r) std::swap(_l,_r);
        int ans=0x3f3f3f3f;
        for(int j=_l;j<=_r;j++)
        {
            if(a[p[j]].dfss<ans) ans=a[p[j]].dfss;
        }
        // printf("%d %d %d\n",a[p[_l]].dfss,a[p[_r]].dfss,ans);
        printf("%d\n",(a[p[_l]].dfss+a[p[_r]].dfss-2*ans));
    }
    
}