#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const int N=1e6+10;
int n, m;
int p[N];
int findth(int x)
{
    if (x == p[x]) return x;
    return p[x] = findth(p[x]);
}

int unionn(int x, int y)
{
    int xx = findth(x);
    int yy = findth(y);
    if (xx != yy) {
        p[yy] = xx;
        return 1;

    }
    return 0;
}
int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n * m;i++) p[i] = i;
    int x1, y1, x2, y2;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
        unionn((x1 - 1)*m + y1, (x2 - 1)*m + y2);
    }
    int sum = 0;
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j < n;j++) {
            if (unionn((j - 1)*m + i, j*m + i))
                sum++;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < m;j++) {
            if (unionn((i - 1)*m + j, (i - 1)*m + j + 1) ) sum += 2;
        }
    }
    printf("%d\n", sum);
    return 0;
}
