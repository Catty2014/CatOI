#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAX = 30;
int map[MAX][MAX];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int R, C;
int ans;

bool InMap(int r, int c)
{
    return (r >= 1 && r <= R && c <= C && c >= 1);
}

void Dfs(int r, int c, int steps)
{
    int nr, nc;
    if (steps > 10 || steps > ans)
    {
        return ;
    }
    for (int i=0; i<4; i++)
    {
        nr = r;
        nc = c;
        if (map[nr+dir[i][0]][nc+dir[i][1]] != 1)
        {
            while (map[nr+dir[i][0]][nc+dir[i][1]] != 1)
            {
                nr += dir[i][0];
                nc += dir[i][1];
                if (!InMap(nr, nc))
                {
                    break;
                }
                if (map[nr][nc] == 3)
                {
                    if (steps + 1 < ans)
                    {
                        ans = steps + 1;
                    }
                    return ;
                }
            }
            if (InMap(nr, nc))
            {
                map[nr+dir[i][0]][nc+dir[i][1]] = 0;
                Dfs(nr, nc, steps + 1);
                map[nr+dir[i][0]][nc+dir[i][1]] = 1;
            }
        }
    }
}

int main()
{
    int sr,sc;
    while (scanf("%d%d", &C, &R) && C && R)
    {
        memset(map, 0, sizeof(map));
        for (int r=1; r<=R; r++)
        {
            for (int c=1; c<=C; c++)
            {
                cin >> map[r][c];
                if (map[r][c] == 2)
                {
                    sr = r;
                    sc = c;
                }
            }
        }
        ans = 999999;
        Dfs(sr, sc, 0);
        (ans > 10) ? cout << "-1" << endl : cout << ans << endl;
    }
    return 0;
}
