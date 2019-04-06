//KMP
#include<cstdio>
#include<cstring>
#include<algorithm>

char k[23333];
int m[23333],p[23333],K,ans,tmp;
const int INF=0x5fff2333;  //ffffffff=-2147483647

int main()
{
    scanf("%s",k+1);
    int len=strlen(k+1);
    scanf("%d",&K);
    tmp=0;
    p[0]=INF;
    for(int i=1;i<=len;i++)
    {
        m[i]=0;
        p[i]=INF;
        for(int j=i+1;j<=len;j++)
        {
            int u=m[j-1];
            while(u && k[u+1+tmp]!=k[j])u=m[u+tmp];
            if(k[u+1+tmp]==k[j]) u++;
            m[j]=u;
            p[j]=p[u+tmp];
            if(m[j]>=K) p[j]=std::min(p[j],m[j]);
            if(p[j]>=K && 2*p[j]<=(j-i+1)-1) ans++;//什么猫饼!
        }
        tmp++;
        // printf("%d\n",ans);;
    }
    printf("%d\n",ans);
    return 0;
}