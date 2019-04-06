//FAKE!!!
#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>

#define FOR for(int i=1;i<=n;i++)

using std::sqrt;
using std::pair;

const int N=100086;
typedef long long ll;
typedef pair<int,int> P;
int v[N],tmp[N];
int m,n,k,last;
std::vector <int> vc[1233];

P _qur(int x)
{
    int id=1;
    for(;x>vc[id].size();id++)
        x-=vc[id].size();
    return std::make_pair(id,x-1);
}

void _rb()
{
    int top=0;
    for(int i=1;i<=last;i++)
    {
        for(int j=0;j<vc[i].size();j++)
        {
            tmp[++top]=vc[i][j];
        }
        vc[i].clear();
    }
    int _k=sqrt(top);
    for(int i=1;i<=top;i++)
    {
        int id=(i-1)/_k +1;
        vc[id].push_back(tmp[i]);
    }
    last=(top-1)/_k +1;
    return;
}

void _ins(int x,int v)
{
    P t=_qur(x);
    vc[t.first].insert(vc[t.first].begin()+t.second,v);
    if(vc[t.first].size()>10*k)
    {
        _rb();
    }
    return ;
}

int main()
{
    scanf("%d",&n);
    k=sqrt(n);
    FOR scanf("%d",&v[i]);
    FOR{
        int id=(i-1)/k +1;
        vc[id].push_back(v[i]);
    }
    last=(n-1)/k +1;
    FOR{
        int op,x,y;
        int _tmp;//no use
        scanf("%d %d %d %d",&op,&x,&y,&_tmp);
        if(op==0)
        {
            _ins(x,y);
        }
        if(op==1)
        {
            P t=_qur(y);
            printf("%d\n",vc[t.first][t.second]);
        }
    }
    return 0;

}