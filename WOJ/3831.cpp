//STD

#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010000
using namespace std;
int cnt=1;char s[N];int h[N],fail[N];
int trans[N][26],ans[N],num,ed[220],n;
inline void insert1(char s[],int id){
    int len=strlen(s+1),p=1;
    for (int i=1,nxt;i<=len;++i){
        if (!trans[p][s[i]-'a']) trans[p][s[i]-'a']=nxt=++cnt;
        else nxt=trans[p][s[i]-'a'];p=nxt;++ans[p];
    }ed[id]=p;
}
struct node{
    int y,next;
}data[N];
inline void insert1(int x,int y){
    data[++num].y=y;data[num].next=h[x];h[x]=num;
}
inline void dfs(int x){
    for (int i=h[x];i;i=data[i].next){
        int y=data[i].y;dfs(y);ans[x]+=ans[y];
    }
}
inline void buildAC(){
    queue<int>q;q.push(1);for (int i=0;i<26;++i) trans[0][i]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for (int i=0;i<26;++i){
            int &y=trans[x][i];
            if (y) fail[y]=trans[fail[x]][i],q.push(y);
            else {y=trans[fail[x]][i];continue;}insert1(fail[y],y);
        }
    }
}
int main(){
//  freopen("bzoj3172.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%s",s+1),insert1(s,i);buildAC();dfs(1);
    for (int i=1;i<=n;++i) printf("%d\n",ans[ed[i]]);
    return 0;
}
