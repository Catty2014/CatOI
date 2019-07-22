#include <cstdio>
typedef long long ll;

const int N=2333333;
char a[N];
int n;
int nxt[N];

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d",&n);
    scanf("%s",a);
    int i=1,j=0;
    ll c=0;
    nxt[0]=nxt[1]=0;
    for(;i<n;i++)
    {
        while(j&&(a[i]!=a[j])) j=nxt[j];
        j+=(a[i]==a[j]);
        nxt[i+1]=j;
    }
    for(i=1;i<=n;i++)
    {
        j=i;
        while(nxt[j]) j=nxt[j];
        if(nxt[i]!=0) nxt[i]=j;
        c+=i-j;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",nxt[i]);
    }
    printf("\n%lld",c);
    return 0;
}
