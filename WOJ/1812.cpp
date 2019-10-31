#include <cstdio>
#include <vector>

int a[13333][133];
int s[12333];
int ans;
std::vector <int> l[10233];
int r[10233][133];
const int M=20123;

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int t=0;
            scanf("%d %d",&t,&a[i][j]);
            if(t==1)l[i].push_back(j);
            if(t==1)r[i][j]=1;
            if(t==1)s[i]++;
        }
    }
    int v;
    scanf("%d",&v);
    int t=0;
    for(int i=1;i<=n;i++)
    {
        t=0;
        ans+=a[i][v];
        for(int j=0;j<v;j++)
        {
            if(r[i][j]==1) t++;
        }
        int mv=(t+a[i][v]-1)%s[i];
        v=l[i][mv];
        /* printf("%d\n",v); */
    }
    printf("%d\n",ans%M);
    return 0;
}

