#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using std::min;
using std::sqrt;
using std::vector;
using std::lower_bound;

vector <int> v[53333];

int idx[53333],vx[53333],lz[53333],k;
int m,n;

void _rs(int id)
{
    v[id].clear();
    for(int i=(id-1)*k+1;i<=min(id*k,n);i++)
    {
        v[id].push_back(vx[i]);
    }
    sort(v[id].begin(),v[id].end());
}

void _add(int x,int y,int z)
{
    for(int i=x;i<=min(idx[x]*k,y);i++)
    {
        vx[i]+=z;
    }
    _rs(idx[x]);
    if(idx[x]!=idx[y])
    {
        for(int i=(idx[y]-1)*k+1;i<=y;i++)
        {
            vx[i]+=z;
        }
        _rs(idx[y]);
    }
    for(int i=idx[x]+1;i<=idx[y]-1;i++)
    {
        lz[i]+=z;
    }
}

int _qur(int x,int y,int z)
{
    int ans=0;
    for(int i=x;i<=min(idx[x]*k,y);i++)
    {
        if(vx[i]+lz[idx[x]]<z) ans++;
    }
    if(idx[x]!=idx[y])
    {
        for(int i=(idx[y]-1)*k+1;i<=y;i++)
        {
            if(vx[i]+lz[idx[y]]<z) ans++;
        }
    }
    for(int i=idx[x]+1;i<=idx[y]-1;i++)
    {
        int tmp=z-lz[i];
        ans+=lower_bound(v[i].begin(),v[i].end(),tmp)-v[i].begin();
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    k=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&vx[i]);
        idx[i]=(i-1)/k+1;
        v[idx[i]].push_back(vx[i]);
    }
    for(int i=1;i<=idx[n];i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    while(m--)
    {
        int op,x,y,z;
        scanf("%d %d %d %d",&op,&x,&y,&z);
        if(op==1) _add(x,y,z);
        else
        {
            printf("%d\n",_qur(x,y,z));
        }
        
    }
    return 0;
}