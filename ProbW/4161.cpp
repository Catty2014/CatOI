#include <algorithm>
#include <cstdio>

using std::max;
using std::min;

int m, n, t;
int a[233], z[233];
int d[23333], p[233][233], g[233][233];  //组权值？

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i], &z[i]);
	}       
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (n - i + 1) * t; j++)
		{
			d[j] = -1;
		}
		for (int j = i; j <= n; j++)
		{
			for (int k = (n - i + 1) * t; k >= a[j]; k--)
			{
				if (d[k - a[j]] > -1) d[k] = max(d[k], d[k - a[j]] + z[j]);
			}
			for (int k = 0; k <= (j - i + 1) * t; k++)
			{
				g[i][j] = max(g[i][j], d[k]);
			}
		}
	}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,m);j++)
        {
            for(int k=j-1;k<i;k++)
            {
                p[i][j]=max(p[i][j],p[k][j-1]+g[k+1][i]);
            }
        }
    }
    printf("%d\n",p[n][m]);
	return 0;
}