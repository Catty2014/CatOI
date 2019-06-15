/* WOJ #2671 凯撒密码 Caesar
 * HASH
 * Nearly STD
 */

#include <cstdio>

const int MOD=998244353; //Awful Number
const int N=500003;
int n,_h[N],ans=0;
char s[N],tmp[12];

int ghs(char c[])
{
    int res=0;
    for(int i=0;i<4;i++)
    {
        res=res*26+(c[i]-c[i+1]+26)%26;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tmp);
        s[i]=tmp[0];
        _h[ghs(tmp)]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tmp);
        int t=_h[ghs(tmp)];
        int m=(tmp[0]-s[t]+26)%26;
        ans=(ans+(i^t^m))%MOD;
    }
    printf("%d\n",ans);
    return 0;
}
