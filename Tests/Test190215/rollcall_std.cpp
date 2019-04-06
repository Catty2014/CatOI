#include<bits/stdc++.h>
#define ll long long
#define N 30005
using namespace std;
inline ll read(){
    ll ans=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
    return ans;
}
inline void write(ll x){
    if(x>9)write(x/10);
    putchar((x%10)^48);
}
ll a[N],ans[N];
struct Node{int tim,id;}b[N];
int n,m;
typedef pair<int,int> pii;
struct fhq_treap{
    int rt,cnt,son[N][2],rd[N],siz[N];
    ll val[N];
    inline int build(ll v){siz[++cnt]=1,rd[cnt]=rand(),val[cnt]=v,son[cnt][0]=son[cnt][1]=0;return cnt;}
    inline void pushup(int p){siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;}
    inline int merge(int a,int b){
        if(!a||!b)return a+b;
        if(rd[a]>rd[b]){son[a][1]=merge(son[a][1],b),pushup(a);return a;}
        son[b][0]=merge(a,son[b][0]),pushup(b);return b;
    }
    inline pii split(int p,int k){
        if(!p)return pii(0,0);
        pii tmp;
        if(siz[son[p][0]]>=k){
            tmp=split(son[p][0],k);
            son[p][0]=tmp.second,pushup(p);
            return make_pair(tmp.first,p);
        }
        tmp=split(son[p][1],k-siz[son[p][0]]-1);
        son[p][1]=tmp.first,pushup(p);
        return make_pair(p,tmp.second);
    }
    inline int rank(int p,ll v){
        if(!p)return 0;
        if(val[p]>v)return rank(son[p][0],v);
        return siz[son[p][0]]+1+rank(son[p][1],v);
    }
    inline ll kth(int k){
        pii x=split(rt,k),y=split(x.first,k-1);
        rt=merge(merge(y.first,y.second),x.second);
        return val[y.second]; 
    }
    inline void insert(ll v){
        int k=rank(rt,v),p=build(v);
        pii x=split(rt,k);
        rt=merge(merge(x.first,p),x.second);
    }
}T;
inline bool cmp(Node a,Node b){return a.tim<b.tim;}
int main(){
    srand(time(NULL));
    n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i].tim=read(),b[i].id=i;
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;++i){
        Node q=b[i];
        for(int j=b[i-1].tim+1;j<=q.tim;++j)T.insert(a[j]);
        ans[q.id]=T.kth(q.id);
    }
    for(int i=1;i<=m;++i)write(ans[i]),puts("");
    return 0;
}
/*
--------------------- 
作者：SC.ldxcaicai 
来源：CSDN 
原文：https://blog.csdn.net/dreaming__ldx/article/details/82120412 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/