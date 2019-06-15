#include <bits/stdc++.h>


//What is this Question asking??

typedef long long ll;

const ll MOD=1e9+7;

int prime[10000086]={0};
bool isnprm[10000086]={1,1};

void primemk()
{
    int k=0;
    for(int i=2;i<=1e7;i++)
    {
        // printf("%d ",i);
        if(isnprm[i]==0)
        {
            prime[++k]=i;
            // printf("%d\n",i);
        }
        for(int j=1;j<=k&&i*prime[j]<10000086;j++)
            {
                // printf("%d\n",i*j);
                isnprm[i*prime[j]]=1;
                if(!(i%prime[j])) break;
            }
    }
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("divisor.in","r",stdin);
    freopen("divisor.out","w",stdout);
    #endif
    // primemk();
    int m;
    scanf("&d",&m);
    int p,a,b,c;
    int ans=0;
    int q=1;
    scanf("%d %d %d %d",&p,&a,&b,&c);
    printf("%d",rand()%c);
    return 0;
}
