#include <cstdio>
#include <cstring>
#include <algorithm>

const int N=233;
const int M=666;
const int I=0x73333333;

int n,m,s,l;//NMSL
int eCnt=1;
int f[N];

struct Edge
{
    int t,n,c;
}e[M];

void edgeAdd(int u,int v,int w)
{
    e[++eCnt].t=v;
    e[eCnt].c=w;
    e[eCnt].n=f[u];
    f[u]=eCnt;
}
