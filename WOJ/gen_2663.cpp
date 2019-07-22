#include <cstdio>
#include <ctime>
#include <cstdlib>

const int MX=1e6;

bool a[MX];
int num;

int main()
{
    srand(time(0));
    freopen("tmp.in","w",stdout);
    const int N=300000;
    const int M=200000;
    int n=rand()%N;
    int m=rand()%M;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)
    {
        int op=rand()%3;
        if(op<=2) op=1;
        else op=2;
        if(op==1&&num<n)
        {
            int car=rand()%n;
            num++;
            a[car]=1;
            printf("1 %d\n",car);
        }
        else
        {
            int car=0;
            do
            {
                car=rand()%n;
            }while(a[car]==0);
            num--;
            a[car]=0;
            printf("2 %d\n",car);
        }
    }
}
