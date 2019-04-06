#include <bits/stdc++.h>
#define MR 0x7fffffff
#define MZ 0x3f3f3f3f
#define NR 0x80000000
#define NZ -2147483600
#define M 10086
#define debug(x) printf("var=%d\n",x)

using namespace std;

bool ladder[13333][133];
int num[13333][133];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            scanf("%d %d",&ladder[i][j],&num[i][j]);
        }
    }
    return 0;
}

