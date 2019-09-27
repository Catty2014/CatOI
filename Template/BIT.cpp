#include <cstdio>

typedef long long ll;

const int N=102333;

ll b[N];
class BIT 
{
private:
    ll a[N];
    int lb(int x)
    {
        return ((x)&(-x));
    }
public:
    int n;
    void add(int k,int x)
    {
        while(k<=n)
        {
            a[k]+=x;
            k+=lb(k);
        }
    }
    void fill(int p,int q,int x)
    {
        add(p,x);
        add(q+1,-x);
    }
    int query(int k)
    {
        ll ret=0;
        while(k>0)
        {
            ret+=a[k];
            k-=lb(k);
        }
        return ret;
    }
};
