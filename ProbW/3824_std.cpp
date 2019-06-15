//STD
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int p[16010],go[16010],K,ans,tmp;
char ch[16010];
int main()
{
    scanf("%s",ch+1);int n=strlen(ch+1);
    scanf("%d",&K);tmp=0;
    go[0]=999999999;
    for(int i=1;i<=n;i++)
    {
        p[i]=0;go[i]=999999999;
        for(int j=i+1;j<=n;j++)
        {
            int u=p[j-1];
            while(u && ch[u+1+tmp]!=ch[j])u=p[u+tmp];
            if(ch[u+1+tmp]==ch[j])u++;
            p[j]=u;
            go[j]=go[u+tmp];
            if(p[j]>=K)go[j]=min(go[j],p[j]);
            if(go[j]>=K && 2*go[j]<=(j-i+1)-1)ans++;
        }
        tmp++;
        // printf("%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}
