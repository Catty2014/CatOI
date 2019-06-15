#include <cstdio>
#include <algorithm>

using std::sort;
typedef long long ll;

int m,n;
ll num[33333];
ll k[33333];

struct OP
{
    int id;//ask the _id_th number
    int a;//how many numbers
}op[33333];

bool cmp(const OP&a,const OP&b)
{
    if(a.a==b.a) return a.id<b.id;
    return a.a<b.a;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("rollcall.in","r",stdin);
        freopen("rollcall.out","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&op[i].a);
        op[i].id=i;
    }    
    sort(op+1,op+m+1,cmp);
    int last=-1;
    for(int i=1;i<=m;i++)
    {
        if(last==op[i].a)
        {
            printf("%d\n",k[op[i].id]);
            continue;
        }
        for(int j=1;j<=op[i].a;j++)
        {
            k[j]=num[j];
        }
        sort(k+1,k+op[i].a+1);
        printf("%d\n",k[op[i].id]);
        continue;
    }
    return 0;
}