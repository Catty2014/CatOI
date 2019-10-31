#include <cstdio>
#include <queue>

class Sudoku
{
public:
    int g[11][11];
    int v[11][11][11];
    std::queue <int> q;
    int cMin,cX,cY;
    int InValid=0;

    void init()
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                for(int k=1;k<=9;k++)
                {
                    v[i][j][k]=1;
                }
                v[i][j][10]=9;
            }
        }
    }

    void clear()
    {
        cMin=233;
        cX=cY=0;
        while(!q.empty()) q.pop();
    }

    void updateValidNumberRow(int x,int a)//---
    {
        for(int i=1;i<=9;i++)
        {
            if(v[x][i][a]) v[x][i][10]--;
            v[x][i][a]=0;
        }
    }

    void updateValidNumberColumn(int y,int a)//|||
    {
        for(int i=1;i<=9;i++)
        {
            if(v[i][y][a]) v[i][y][10]--;
            v[i][y][a]=0;
        }
    }

    void updateValidNumberBlock(int x,int y,int a)
    {
        int bx=(x+2)/3;
        int by=(y+2)/3;
        for(int i=bx*3-2;i<=bx*3;i++)
        {
            for(int j=by*3-2;j<=by*3;j++)
            {
                if(v[i][j][a]) v[i][j][10]--;
                v[i][j][a]=0;
            }
        }
    }
    
    void updateValidNumberMain()
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                updateValidNumberRow(i,g[i][j]);
                updateValidNumberBlock(i,j,g[i][j]);
                updateValidNumberColumn(j,g[i][j]);
                /* if(v[i][j][g[i][j]]==0&&g[i][j]!=0) InValid=1; */
                if(v[i][j][10]==1) q.push(i*10+j);
                if(v[i][j][10]<cMin) 
                {
                    cMin=v[i][j][10];
                    cX=i;
                    cY=j;
                }
            }
        }
    }

    int fillOnlyNumber()
    {
        int r=0;
        while(!q.empty())
        {
            r++;
            int p=q.front();
            q.pop();
            int x=p/10;
            int y=p%10;
            for(int i=1;i<=9;i++)
            {
                if(v[x][y][i]) g[x][y]=i;
            }
        }
        return r;
    }

}s;

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            scanf("%d",&s.g[i][j]);
        }
    }
    s.updateValidNumberMain();
    s.fillOnlyNumber();
    if(s.InValid==1)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            printf("%d ",s.g[i][j]);
        }
        printf("\n");
    }

    return 0;

}
