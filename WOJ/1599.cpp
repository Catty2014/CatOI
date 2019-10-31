//std
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

#define SIZE 210

using namespace std;

string s[SIZE];
int hit[SIZE][2], score[SIZE];

int main(void)
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    int n = 1, i, res = 0;
    while (cin >> s[n])
    {
        ++n;
    }
    --n;
    for (i = 1; i <= n; ++i)
    {
        if (s[i][0] == '/')
        {
            hit[i][0] = 10;
        }
        else if (s[i][1] == '/')
        {
            hit[i][0] = s[i][0] - '0';
            hit[i][1] = 10 - hit[i][0];
        }
        else
        {
            hit[i][0] = s[i][0] - '0'; // 每轮的击中数
            hit[i][1] = s[i][1] - '0';
        }
    }
    for (i = 10; i; --i)
    {
        if (s[i][0] == '/') // 第一次就全部击中
        {
            score[i] = hit[i+1][0] + ((s[i+1].size() < 2) ? hit[i+2][0] : hit[i+1][1]) + 10;
        }
        else if (s[i][1] == '/') // 第二次全部击中
        {
            score[i] = hit[i+1][0] + 10;
        }
        else // 没有全部击中
        {
            score[i] = hit[i][0] + hit[i][1];
        }
        res += score[i];
    }
    int sum[12];
    sum[0]=0;
    for(int i=1;i<=10;i++)
    {
        printf("%d ",score[i]);
        sum[i]=sum[i-1]+score[i];
    }
    printf("\n");
    for(int i=1;i<=10;i++)
    {
        printf("%d ",sum[i]);
    }
    return 0;
}
