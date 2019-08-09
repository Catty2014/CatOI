/****************************************
 * W1846 Sudoku
 * Maybe..DFS?
 ****************************************/

#include <cstdio>

const int N=11;


class Sudoku
{
private:
    int a[N][N];
    bool v[N][N][N];
public:
    void initValidNumber()
    {
        for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++)
                for(int k=1;k<=9;k++)
                    v[i][j][k]=1;
        return ;
    }
    int getLineValidNumber(int x)
    {
        int mv[11];
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                mv[j]+=v[x][i][j];
            }
        }
        for(int i=1;i<=9;i++)
        {
            if(mv[i]==1)
            {
                return i;
            }
        }
        return 0;
    }
    int findLineValidNumber(int x,int w)
    {
        for(int i=1;i<=9;i++)
        {
            if(v[x][i][w]==1)
            {
                return i;
            }
        }
        return 0;
    }
    int getRowValidNumber(int y)
    {
        int mv[11];
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                mv[j]+=v[i][y][j];
            }
        }
        for(int i=1;i<=9;i++)
        {
            if(mv[i]==1)
            {
                return i;
            }
        }
        return 0;
    }
    int findRowValidNumber(int y,int w)
    {
        for(int i=1;i<=9;i++)
        {
            if(v[i][y][w]==1)
            {
                return i;
            }
        }
        return 0;
    }
    int getBlockValidNumber()
    {

    }
    int findRowValidNumber()
    {

    }
    void setValidNumber(int x,int y,int w)
    {
        for(int i=1;i<=9;i++)
        {
            v[i][y][w]=0;
            v[x][i][w]=0;
            v[x][y][i]=0;
        }
        int rx=(x-1)/3;
        int ry=(y-1)/3;
        for(int i=rx*3+1;i<=rx*3+3;i++)
        {
            for(int j=ry*3+1;j<=ry*3+3;j++)
            {
                v[i][j][w]=0;
            }
        }
        return ;
    }
    void fillNumber(int x,int y,int v)
    {
        a[x][y]=v;
        setValidNumber(x,y,v);
        return ;
    }
    int fillOnlyNumber(int x,int y)
    {
        int cnt=0,num=0;
        for(int i=1;i<=9;i++)
        {
            cnt+=v[x][y][i];
            num=(v[x][y][i])?i:num;
        }
        if(cnt==1)
        {
            fillNumber(x,y,num);
        }
        else
        {
            cnt=0;
        }
        return cnt;
    }
    int fetchOnlyNumber()
    {
        int cnt=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                cnt+=fillOnlyNumber(i,j);
            }
        }
        return cnt;
    }
    void fillAloneNumber()
    {
        for(int i=1;i<=9;i++)
        {
            int tmp=0;
            while((tmp=getLineValidNumber(i))!=0)
            {
                fillNumber(i,findLineValidNumber(i,tmp),tmp);
            }
        }
        for(int i=1;i<=9;i++)
        {
            int tmp=0;
            while((tmp=getRowValidNumber(i))!=0)
            {
                fillNumber(findRowValidNumber(i,tmp),i,tmp);
            }
        }
    }
    void showSudoku()
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                printf("%d%c",a[i][j],(j!=9)?' ':'\n');
            }
        }
    }
};

Sudoku s;

int main(void)
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    s.initValidNumber();
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int t;
            scanf("%d",&t);
            if(t!=0)s.fillNumber(i,j,t);
        }
    }
    int cnt = 0;
    int tmp=20;
    do{
        cnt=s.fetchOnlyNumber();
        s.fillAloneNumber();
    /* }while(cnt!=0); */
    }while(tmp--);
    s.showSudoku();
    return 0;
}
