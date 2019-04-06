/****************************************
 * STD:W1566 骑士
 * SCDP
 * 双状态?
 * 究极递推？
 ****************************************/

#include <cstdio>

typedef long long ll;
const int N=10;
const int M=(1<<8);

int la[M][M],lb[M][M];
ll f[N][35][M][M];//<-so scary!
int s[M];
int x,y,st;

#define lb(x) (x&(-x))

int chk(int i,int j,int w)
{
    int k;
    while(i){
        k=lb(i);
        if((j&(k<<w)) || (j&(k>>w))) return 0;
        i-=k;
    }
    return 1;
}



int main()
{
    scanf("%d %d",&x,&y);
    if(y>32)//???
    {
        printf("0\n");
        return 0;
    }
    st=(1<<x)-1;
    for(int i = 0; i<=st ; ++i)
    {
    // printf("DEBUG!!!\n");
        int x=i;
        while(x){
            x-=lb(x);
            s[i]++;
        }
    }
    for(int i=0;i<=st;++i)
    {
        for(int j = 0; j <=st ; j++)    
        {
    // printf("DEBUG!!!\n");
            la[i][j]=la[j][i]=chk(i,j,2);//Modified:2
            lb[i][j]=lb[j][i]=chk(i,j,1);//Modified:1
        }
    }
    f[0][0][0][0]=1;//Init
    for(int i = 0; i < x; i++)
    {
        for(int j=0; j <=y ; j++)
        {
            for(int k1=0;k1<=st;k1++)
            {
                for(int k2=0;k2<=st;k2++)
                {
                    if(f[i][j][k1][k2])
                    {
                        for(int ls=0;ls<=st;ls++)
                        {
                            if(lb[k1][ls] && la[k2][ls] && (j+s[ls]<=y))
                            {
                                f[i+1][j+s[ls]][k2][ls]+=f[i][j][k1][k2];
                            }
                        }
                    }
                }
            }
        }
    }
    // printf("DEBUG!!!\n");
    ll ans=0;
    for(int i=0;i<=st;i++)
    {
        for(int j=0;j<=st;j++)
        {
            ans+=f[x][y][i][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}