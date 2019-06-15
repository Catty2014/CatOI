/* Test181230
 * VIOLENCE?!!!!
 * True_STD
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in read()
#define pb push_back
inline int read(){
    int x=0,f=1;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';return x*f;
}
const int mod=1e9+7;
const int maxn = 3e3+10;
int n,m,a[maxn],s1[maxn],s2[maxn],dp[maxn];
signed main(){
    n=in;m=in;
    for(int i=1;i<=n;i++){
        a[i]=in;
        s1[i]=s1[i-1]+(a[i]==1);
                s2[i]=s2[i-1]+(a[i]==2);
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=i;
        for(int j=0;j<i;j++){
            int sum1=s1[i]-s1[j],sum2=s2[i]-s2[j];
            if(sum1&&sum2&&abs(sum1-sum2)>m)continue;
            dp[i]=min(dp[i],dp[j]+1);
        }
    }
    cout<<dp[n];
    return 0;
}