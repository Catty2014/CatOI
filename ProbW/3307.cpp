/*WOJ #3307 数对
 *HASH
 *NSTD //Nearly STD
 */

#include <cstdio>

int a[233333];
const int MOD=2333333;
int num=0;
int fi[2333666]; //MEMORY BOOM!

//What a magic name!
struct _3307
{
    int v,n,s;
}e[233333];

void _add (int x,int y)
{
    for(int i=fi[x];i;i=e[i].n)
    {
        if(e[i].v=y)
        {
            e[i].s++;
            return;
        }
    }
    ++num;
    e[num].v=y;
    e[num].s++;
    e[num].n=fi[x];
    fi[x]=num;
    return ;
}

int qur(int x,int y)
{
    for(int i=fi[x];i;i=e[i].n)
    {
        if(e[i].v=y)
        {
            return e[i].s;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n,c;//N:num; C:"C"
    scanf("%d %d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]-c<0) continue;
        _add((a[i]-c)%MOD,a[i]-c);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=qur((a[i])%MOD,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
