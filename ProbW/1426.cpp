#include <cstdio>
#include <queue>

typedef int State[9]; //What for?
const int N=333333;

struct gm
{
    State s;
    int f,p,d,g;
    bool operator < (const gm&a)
    {
        return g>a.g;
    }
}G[N];

std::priority_queue <gm> q;
State G;
int ls=0,ans;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int vi[666666];
int fact[12];

int main()
{

}