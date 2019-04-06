//QAQ
#include <cstdio>

int n,m;

bool cn[6333][6333];
bool cm[6333][6333];
bool vi[6333];
int ans[6333];
int ansc;
int lstmp;

bool dfs(int t,int st)
{
    if(vi[t]==1 && st==0) return false;
    vi[t]=1;
    int tmp=0;
    // printf("t=%d\n",t);
    for(int i=1;i<=n;i++)
    {
        // printf("t=%d i=%d v=%d\n",t,i,vi[i]);
        if(cm[t][i]==1) {if(vi[i]==1) tmp++;dfs(i,0);}
        
    }
    // printf("tmp=%d lstmp=%d\n",tmp,lstmp);
    lstmp=(tmp>lstmp)?tmp:lstmp;
    if(lstmp>=2 && st==1) return false;
    return true;
}

bool solve(int t)
{
    lstmp=0;
    if(dfs(t,1)==false) return false;
    // for(int i=1;i<=n;i++)
    // {
        // printf("vi %d\n",vi[i]);
    // }
    // printf("\n");
    for(int i=1;i<=n;i++)
    {
        if(vi[i]!=1) return false;
    }
    return true;
    lstmp=0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("tree.in","r",stdin);
        freopen("tree.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);    
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        if(p>6333 || q>6333) {printf("%d %d\n",p,q);return 0;}
        cm[p][q]=cn[p][q]=cm[q][p]=cn[q][p]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vi[j]=0;
            cm[i][j]=0;
            cm[j][i]=0;
        }
        // for(int qw=1;qw<=n;qw++)
        // {
            // for(int er=1;er<=n;er++)
            // {
                // printf("%d ",cm[qw][er]);
            // }
            // printf("\n");
        // }
        bool ac=0;
        vi[i]=1;
        if(i!=1) ac=solve(1);
        else ac=solve(2);
        vi[i]=0;
        if(ac==1)
        {
            ans[++ansc]=i;
        }
        for(int j=1;j<=n;j++)
        {
            cm[i][j]=cn[i][j];
            cm[j][i]=cn[j][i];
        }
    }
    printf("%d\n",ansc);
    for(int i=1;i<=ansc;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}