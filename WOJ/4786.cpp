#include<bits/stdc++.h>
#define N 2010
#define D 26
using namespace std;
bool isabc(char ch){
    return (ch>='a')&&(ch<='z');
}
template<typename T> void Read(T &X){
    X=0;char C=getchar();
    for (;!isdigit(C);C=getchar());
    for (; isdigit(C);C=getchar()) X=(X<<3)+(X<<1)+C-'0';
}
int T,len,m,Q;
int L,R,tot;
int cnt[D],cnt2[D];
int q[N][D];
int g[N],f[N];
bool vis[N];
int tmp;
char ch;
int s[N];
int ans;
void add(int x,int sig){
    if (f[cnt2[x]]>g[cnt2[x]]) tot--;else tot++;
    f[cnt2[x]]--;
    cnt2[x]+=sig;
    if (f[cnt2[x]]>=g[cnt2[x]]) tot++;else tot--;
    f[cnt2[x]]++;
    return;
}
int main(){
    Read(T);
    while (T--){
        Read(m);Read(Q);
        tmp=0;
        ch=getchar();
        for (;!isabc(ch);ch=getchar());
        for (; isabc(ch);ch=getchar()) s[++tmp]=ch-'a';
        for (int i=1;i<=m;i++){
            for (int j=0;j<D;j++) q[i][j]=q[i-1][j];
            q[i][s[i]]++;
        }
        while (Q--){
            for (int i=0;i<D;i++) cnt[i]=cnt2[i]=0;
            Read(L);Read(R);
            len=R-L+1;
            for (int i=0;i<D;i++){
                cnt[i]=q[R][i]-q[L-1][i];
                cnt2[i]=q[len][i];
                g[cnt[i]]++;
                f[cnt2[i]]++;
            }
            tot=0;
            for (int i=0;i<D;i++)
                if (!vis[cnt[i]]){
                    vis[cnt[i]]=true;
                    tot+=g[cnt[i]];
                }
            for (int i=0;i<D;i++) vis[cnt[i]]=false;
            for (int i=0;i<D;i++)
                if (!vis[cnt2[i]]){
                    vis[cnt2[i]]=true;
                    if (f[cnt2[i]]>g[cnt2[i]]) tot+=f[cnt2[i]]-2*g[cnt2[i]];
                    else tot-=f[cnt2[i]];
                }
            for (int i=0;i<D;i++) vis[cnt2[i]]=false;
            ans=0;
            if (!tot) ans++;
            for (int i=len+1;i<=m;i++){
                add(s[i],1);
                add(s[i-len],-1);
                if (!tot) ans++;
            }
            printf("%d\n",ans);
            for (int i=0;i<D;i++){
                g[cnt[i]]--;
                f[cnt2[i]]--;
            }
        }
    }
    return 0;
}
