#include <cstdio>
#include <cstring>

int a[12][12];
bool v[12][12][12];

int getCount(int x,int y)
{
    int ans=0;
    for(int i=1;i<=9;i++)
    {
        ans+=v[x][y][i];
    }
    return ans;
}

void resVal(int x,int y,int w)
{
    for(int i=1;i<=9;i++)
        v[x][y][i]=w;
}

int refValidNumber(int x,int y)
{
    resVal(x,y,1);
    for(int i=1;i<=9;i++)
    {
        if(a[x][i]) v[x][y][a[x][i]]=0;
        if(a[i][y]) v[x][y][a[i][y]]=0;
    }
    int bx=(x-1)/3;
    int by=(y-1)/3;
    for(int i=bx*3+1;i<=bx*3+3;i++)
        for(int j=by*3+1;j<=by*3+3;j++)
        {
            if(a[i][j]) v[x][y][a[i][j]]=0;
        }
    int nowCount=getCount(x,y);
    return (nowCount);
}

int filValidNumber(int x,int y)
{
    int ans=0;
    for(int i=1;i<=9;i++)
    {
        ans=(v[x][y][i]==1)?i:ans;
    }
    a[x][y]=ans;
    return ans;
}

void filOnlyNumber()
{
    int ap[11];
    int plc[11];
    memset(ap,0,sizeof(ap));
    memset(plc,0,sizeof(plc));
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(v[i][j][k]==1)
                {
                    plc[k]=j;
                    ap[k]++;
                }
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(ap[j]==1)
            {
                a[i][plc[j]]=j;
                resVal(i,plc[j],0);
            }
        }
        memset(ap,0,sizeof(ap));
        memset(plc,0,sizeof(plc));
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(v[j][i][k]==1)
                {
                    plc[k]=j;
                    ap[k]++;
                }
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(ap[j]==1)
            {
                a[plc[j]][i]=j;
                resVal(plc[j],i,0);
            }
        }
        memset(ap,0,sizeof(ap));
        memset(plc,0,sizeof(plc));
    }
}

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
            scanf("%d",&a[i][j]);
            resVal(i,j,0);
        }
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(a[i][j]==0)
                refValidNumber(i,j);
        }
    }
    int cnt=0;
    int cache=0;
    do{
        cnt=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(a[i][j]==0)
                {
                    int prevCount=getCount(i,j);
                    int ctmp=0;
                    ctmp=refValidNumber(i,j);
                    cnt+=prevCount-ctmp;
                    if(ctmp==1)
                    {
                        int tmp2=filValidNumber(i,j);
                        resVal(i,j,0);
                        for(int k=1;k<=9;k++)
                        {
                            v[i][k][tmp2]=0;
                            v[j][i][tmp2]=0;
                        }
                    }
                }
            }
        }
        filOnlyNumber();
        if(cnt==0)
        {
            /* cache++; */
        }
        cache++;
    }while(cache<=50);
    /* }while(cnt!=0&&cache<=8); */
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
