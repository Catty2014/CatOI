//Emmm..
//似乎不用树链剖分也行...?

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define il inline
#define maxn 200005
#define lid id << 1
#define rid (id << 1) | 1
#define ll long long
using namespace std;
il int read(){ int x = 0 , w = 1; char ch = getchar();while (ch < '0' || ch > '9'){if (ch == '-') w = -1;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}return x * w;}
struct edge{
    int to , next;  
}e[maxn << 1];
struct tree{
    int l , r , min;    
}t[maxn << 2];
int head[maxn] , cnt , val[maxn] , f[maxn][22] , tot , dep[maxn] , q[maxn];
int l[maxn] , r[maxn];
void add(int u ,int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;  
}
void dfs(int u,int fa){
    l[u] = ++tot , q[tot] = u;
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for ( int i = 1 ; i <= 20; ++i) 
        f[u][i] = f[f[u][i - 1]][i - 1];
    for ( int i = head[u] ; i ; i = e[i].next){
         int to = e[i].to;
        if (to != fa){
            dfs(to , u);
        }
    }
    r[u] = tot;
}
void pushup(int id){
    t[id].min = min (t[lid].min , t[rid].min);  
}
void build(int id,int l,int r){
    t[id].l = l , t[id].r = r;
    if (l == r) {t[id].min = val[q[l]];return;}
     int mid = (l + r) >> 1;
    build(lid , l ,mid);
    build(rid , mid + 1 , r);
    pushup(id);
}
void update(int id,int pos,int x){
    if (pos == t[id].l && t[id].l == t[id].r) {t[id].min = x;return;}
     int mid = (t[id].l + t[id].r) >> 1;
    if (pos <= mid) update(lid , pos , x);
    else update(rid , pos , x);
    pushup(id);
}
int query(int id,int l,int r){
    if (l > r) return 1000000000;
    if (t[id].l == l && t[id].r == r) return t[id].min;
     int mid = (t[id].l + t[id].r) >> 1;
    if (r <= mid) return query(lid , l ,r);
    else if (l > mid) return query(rid , l ,r);
    else return min(query(lid , l , mid) , query(rid , mid + 1 , r));
}
char id[20];
int main(){
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n = read(), m = read() , fa , x , y;
    for ( int i = 1; i <= n;++i){
        fa = read() , val[i] = read();
        if (fa) add (fa , i);
    }
    int rt = 1;
    dfs(1 , 0);
    build(1 , 1 , n);
    for ( int i = 1 ; i <= m ; ++i){
        scanf("%s",id);
        if (id[0] == 'E') rt = read();
        else if (id[0] == 'V') {
            x = read() , y = read();
            update(1 , l[x] , y);
        }
        else{
            x = read();
            if (x == rt) printf("%d\n",t[1].min);
            else if (l[x] <= l[rt] && r[rt] <= r[x]){
                 int depth = dep[rt] - dep[x] - 1 , y = rt;
                for ( int i = 0 ; i <= 20 ;++i) if (depth & (1 << i)) y = f[y][i];
                printf("%d\n",min ( query(1 , 1 , l[y] - 1) , query(1 , r[y] + 1 , n) ));   
            }
            else printf("%d\n",query(1 , l[x] , r[x]));
        }
    }
    return 0;
}  
