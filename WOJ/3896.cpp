#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
const int I=0x33333333;
const int N=2333;

int t,n;
int l[N],s[N];

std::vector <int> div(int n)
{
    std::vector<int> r;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            r.push_back(i);
            if(i!=n/i) r.push_back(n/i);
        }
    }
    return r;
}


int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    while(scanf("%d",&n)!=-1)
    {
        std::vector<int> a=div(n);
        sort(a.begin(),a.end());
        memset(l,0,sizeof(l));
        memset(s,0,sizeof(s));
        int m=a.size();
        l[m-1]=0;
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i+1;j<(int)a.size();j++)
            {
                if(a[j]%a[i]==0)
                {
                    l[i]=l[j]+1;
                    break;
                }
            }
        }
        s[m-1]=1;
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i+1;j<m;j++)
            {
                if(l[j]+1==l[i] && a[j]%a[i]==0)
                {
                    s[i]+=s[j];
                }
            }
        }
        printf("%d %d\n",l[0],s[0]);
    }
    return 0;
}
