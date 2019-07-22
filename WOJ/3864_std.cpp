#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
inline int rd(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
inline void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return ;
}
struct node{
    int l,r;
    long long maxn,minn;
    long long sum;
    int f;
}tree[400006];
int n,m;
void build(int i,int x,int y){
    tree[i].l=x,tree[i].r=y;
    if(x==y){
        tree[i].maxn=rd();
        tree[i].sum=tree[i].minn=tree[i].maxn;
        return ;
    }
    int mid=(x+y)>>1;
    build(i*2,x,mid);
    build(i*2+1,mid+1,y);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].maxn=max(tree[i*2].maxn,tree[i*2+1].maxn);
    tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
    return ;
}
void pushdown(int x){
    if(!tree[x].f) return ;
    int h=tree[x].f;
    tree[x*2].f+=h,tree[x*2+1].f+=h;
    tree[x*2].sum-=(tree[x*2].r-tree[x*2].l+1)*h,tree[x*2+1].sum-=(tree[x*2+1].r-tree[x*2+1].l+1)*h;
    tree[x*2].maxn-=h,tree[x*2+1].maxn-=h,tree[x*2].minn-=h,tree[x*2+1].minn-=h;
    tree[x].f=0;
    return ;
}
void extract_a_root(int i,int x,int y){
    if(tree[i].l>=x&&tree[i].r<=y&&(tree[i].maxn-(long long)sqrt(tree[i].maxn))==(tree[i].minn-(long long)sqrt(tree[i].minn))){
        int h=tree[i].minn-(int)sqrt(tree[i].minn);
        tree[i].f+=h;
        tree[i].sum-=((tree[i].r-tree[i].l+1)*h);
        tree[i].maxn-=h;
        tree[i].minn-=h;
        return ;
    }
    if(tree[i].l>y||tree[i].r<x) return ;
    pushdown(i);
    if(tree[i*2].r>=x) extract_a_root(i*2,x,y);
    if(tree[i*2+1].l<=y) extract_a_root(i*2+1,x,y);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].maxn=max(tree[i*2].maxn,tree[i*2+1].maxn);
    tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
    return ;
}
long long solve(int i,int x,int y){
    if(tree[i].l>=x&&tree[i].r<=y) return tree[i].sum;
    if(tree[i].l>y||tree[i].r<x) return 0;
    pushdown(i);
    long long num=0;
    if(tree[i*2].r>=x) num+=solve(i*2,x,y);
    if(tree[i*2+1].l<=y) num+=solve(i*2+1,x,y);
    return num;
}
int main(){
    n=rd();
    build(1,1,n);
    m=rd();
    for(int i=1;i<=m;i++){
        int f=rd(),x=rd(),y=rd();
        if(f==2) extract_a_root(1,x,y);
        if(f==1) write(solve(1,x,y)),puts("");
    }
    return 0;
}