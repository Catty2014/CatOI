#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
const int N=100233;
const int M=510233;
const int CH=(int)'a';
const double eps=(double)1e-7;
typedef long long ll;

int s[M][27];
char st[M];
bool v[M];
int tms[M];
int ti;
int rt,tt;
int n;
ll ans;
int size[N];
std::vector <int> mp[N];

void ins()
{
    int l=strlen(st+1);
    int p=rt;
    int i=l;
    for(;i;i--)
    {
        if(!s[p][st[i]-CH])
        {
            s[p][st[i]-CH]=++tt;
        }
        p=s[p][st[i]-CH];
    }
    v[p]=1;
}

void dfs(int x)
{
    
}

int main()
{
    
}
