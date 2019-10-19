#include <cstdio>
#include <cstdlib>
#include <cstring>

int ans[100][4];

int tk;

class Mayan
{
public:
    int t[6][8];
    int a[6][8];
    void clearAll()
    {
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
    }
    void copy(int tp)
    {
        if(tp==1)
        {
            memcpy(t,a,sizeof(a));
        }
        else
        {
            memcpy(a,t,sizeof(a));
        }
    }
    void showA()
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=7;j++)
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
    int mark()
    {
        int val=0;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=7;j++)
            {
                if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]&&a[i][j+2]!=0)
                {
                    a[i][j]=a[i][j+1]=a[i][j+2]=0;
                    val=1;
                }
                if(a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j]&&a[i+2][j]!=0)
                {
                    a[i][j]=a[i+1][j]=a[i+2][j]=0;
                    val=1;
                }
            }
        }
        return val;
    }
    void fall()
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=2;j<=7;j++)
            {
                while(a[i][j]!=0 && a[i][j-1]==0&&j-1>=1)
                {
                    a[i][j-1]=a[i][j];
                    a[i][j]=0;
                    j--;
                }
            }
        }
    }
    int empty()
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=7;j++)
            {
                if(a[i][j]) return 0;
            }
        }
        return 1;
    }
    void fail()
    {
        int c[11]={0};
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=7;j++)
            {
                c[a[i][j]]++;
            }
        }
        for(int i=1;i<=10;i++)
        {
            if(c[i]>0&&c[i]<3)
            {
                printf("-1\n");
                exit(0);
            }
        }
    }
}m;

void dfs(int k)
{
    /* m.showA(); */
    /* printf("\n%d\n",k); */
    if(k==tk+1)
    {
        if(m.empty())
        {
            for(int i=1;i<=tk;i++)
            {
                printf("%d %d %d\n",ans[i][i-1],ans[i][2]-1,ans[i][3]);
            }
            exit(0);
        }
        return ;
    }
    for(int xx=1;xx<=5;xx++)
    {
        for(int yy=1;yy<=7;yy++)
        {
            if(m.a[xx][yy])
            {
                m.copy(1);
                if(xx>1&&(m.a[xx-1][yy]==0))
                {
                    m.a[xx-1][yy]=m.a[xx][yy];
                    m.a[xx][yy]=0;
                    while(m.mark())
                    {
                        m.fall();
                    }
                    ans[k][1]=xx;
                    ans[k][2]=yy;
                    ans[k][3]=-1;
                    dfs(k+1);
                    m.copy(0);
                }
                if(xx<5&&m.a[xx+1][yy]!=m.a[xx][yy])
                {
                    int p=m.a[xx][yy];
                    m.a[xx][yy]=m.a[xx+1][yy];
                    m.a[xx+1][yy]=p;
                    while(m.mark())
                    {
                        m.fall();
                    }
                    ans[k][1]=xx;
                    ans[k][2]=yy;
                    ans[k][3]=1;
                    dfs(k+1);
                    m.copy(0);
                }
            }
        }
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    m.clearAll();
    scanf("%d",&tk);
    for(int i=1;i<=5;i++)
    {
        int tp=1;
        int v=0;
        do
        {
            scanf("%d",&v);
            m.a[i][tp++]=v;
        }while(v!=0);
    }
    m.fail();
    dfs(0);
    printf("-1\n");
    return 0;
}
