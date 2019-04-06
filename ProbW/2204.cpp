/*WOJ #2204 秘密消息 
 *Trie (without char)
 */

#include <cstdio>
#include <cstring>

int read() {
    int ans=0,f=1; char i=getchar();
    while(i<'0' || i>'9') {if(i=='-') f=-1; i=getchar();}
    while(i>='0' && i<='9') {ans=(ans<<1)+(ans<<3)+i-'0'; i=getchar();}
    return ans*f;
}

int a[133333];
int chk[133333][3];
int size;
int end[133333];
int pass[133333];
#define MSA memset(a,0,sizeof(a))
#define MSB memset(chk[size],0,sizeof(chk[size]))

void ins(int n)
{
    int u=0;
    for(int i=1;i<=n;i++)
    {
        if(chk[u][a[i]]==0)
        {
            //MSB;
            chk[u][a[i]]=++size;
        }
        
        u=chk[u][a[i]];
        pass[u]++;
    }
    end[size]++;
    return ;
}

int qur(int n)
{
    int u=0,ret=0;
    for(int i=1;i<=n;i++)
    {
        /*
        p=trie[p][a[i]];
        if(!p) return ans;
        if(i!=k) ans+=cnt[p];
        else ans+=size[p];
        */
       u=chk[u][a[i]];
       if(u==0) 
       {
           return ret;
       }
       ret+=pass[u];
    }
    ret=ret-end[u]+pass[u];
    return ret;
}

int main(int argc, char const *argv[])
{
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=1;i<=M;i++)
    {
        MSA;
        int n;
        n=read();
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
        }
        ins(n);
        
    }
    for(int i=1;i<=N;i++)
    {
        MSA;
        int n;
        n=read();
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
        }
        printf("%d\n",qur(n));
    }
    return 0;
}
