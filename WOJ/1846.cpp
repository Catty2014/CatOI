#include <cstdio>
int g[12][12];
int v[12][12][12];
const int n=9;

void showSudoku()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            printf("%d%c",g[i][j],(j==9)?'\n':' ');
        }
    }
    return ;
}

void updateValidLine(int x,int p)
{
    for(int i=1;i<=9;i++)
    {
        if(v[x][i][p]==1) v[x][i][10]--;
        v[x][i][p]=0;
    }
}

void updateValidColumn(int y,int p)
{
    for(int i=1;i<=9;i++)
    {
        if(v[i][y][p]==1) v[i][y][10]--;
        v[i][y][p]=0;
    }
}

void updateValidBlock(int x,int y,int p)
{
    int bx=(x-1)/3;
    int by=(y-1)/3;
    for(int i=1;i<=3;i++)
    {
        if(v[bx*3+i][y][p]) v[bx*3+i][y][10]--;
        v[bx*3+i][y][p]=0;
        if(v[x][by*3+i][p]) v[x][by*3+i][10]--;
        v[x][by*3+i][p]=0;
    }
}

void updateValidMain();

void selectOnly()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(v[i][j][10]==1&&g[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(v[i][j][k]==1) g[i][j]=k;
                }
                updateValidMain();
            }
        }
    }

}

void updateValidMain()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(g[i][j]!=0) 
            {
                updateValidLine(i,g[i][j]);
                updateValidColumn(j,g[i][j]);
                updateValidBlock(i,j,g[i][j]);
            }
        }
    }
}

int main(void)
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            scanf("%d",&g[i][j]);
            for(int k=1;k<=9;k++)
            {
                v[i][j][k]=1;
            }
            v[i][j][10]=9;
        }
    }
    /* showSudoku(); */
    updateValidMain();
    selectOnly();
    updateValidMain();
    selectOnly();
    updateValidMain();
    selectOnly();
    showSudoku();
    return 0;
}
