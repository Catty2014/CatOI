//注意:这是标程!!!
//仅用于对拍!!!
//这里只是为了方便复制代码到我的Arch上!!!
#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc (p<<1|1)
const int N=2e5+10;
inline void read(int &x){
    x=0;
    char ch=getchar();
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
struct Segment_Tree{
    struct Node{
        int lsum,rsum,sum,lson,rson,len;
    }T[N<<2];
    void PushUp(int p){
        T[p].len=T[lc].len+T[rc].len;
        if(T[lc].len==T[lc].lsum)T[p].lsum=T[lc].len+T[rc].lsum;
        else T[p].lsum=T[lc].lsum;
        if(T[rc].len==T[rc].rsum)T[p].rsum=T[rc].len+T[lc].rsum;
        else T[p].rsum=T[rc].rsum;
        T[p].sum=max(T[lc].rsum+T[rc].lsum,max(T[lc].sum,T[rc].sum));
    }
    void Build(int p,int l,int r){
        T[p].lson=l;
        T[p].rson=r;
        if(l==r){
            T[p].lsum=T[p].rsum=T[p].sum=1;
            T[p].len=1;
            return;
        }
        int mid=(l+r)>>1;
        Build(lc,l,mid);
        Build(rc,mid+1,r);
        PushUp(p);
    }
    void Update(int p,int pos,int val){
        if(T[p].lson==pos&&T[p].rson==pos){
            T[p].lsum=T[p].rsum=T[p].sum=val;
            return;
        }
        int mid=(T[p].lson+T[p].rson)>>1;
        if(pos<=mid)Update(lc,pos,val);
        else Update(rc,pos,val);
        PushUp(p);
    }
    inline int Query(int p,int val){
        if(T[p].lson==T[p].rson)return T[p].lson;
        int mid=(T[p].lson+T[p].rson)>>1;
        if(T[lc].sum>=val)return Query(lc,val);
        else if(T[lc].rsum+T[rc].lsum>=val)return mid-T[lc].rsum+1;
        else return Query(rc,val);
    }
}Tree;
int pos[1000010];
int n,m;
int main(){
    freopen("tmp.in","r",stdin);
    freopen("tmp.ans","w",stdout);
    read(n);
    read(m);
    Tree.Build(1,1,n);
    while(m--){
        int opt,x;
        read(opt);
        read(x);
        if(opt==2){
            Tree.Update(1,pos[x],1);
            pos[x]=0;
        }
        else{
            int len=Tree.T[1].sum;
            if(Tree.T[1].lsum-1>=(len-1)/2)pos[x]=1,Tree.Update(1,pos[x],0);
            else if(Tree.T[1].rsum-1>(len-1)/2)pos[x]=n,Tree.Update(1,pos[x],0);
            else{
                if(len%2==0)len--;
                int Id=Tree.Query(1,len);
                pos[x]=(Id+Id+len-1)/2;
                Tree.Update(1,pos[x],0);
            }
            cout<<pos[x]<<'\n';
        }
    }
}
