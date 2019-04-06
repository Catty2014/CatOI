#include <bits/stdc++.h>
using namespace std;
int a[23];

int main()
{
    int n;
    scanf("%d",&n);
    int sum;
    scanf("%d",&sum);
    for(int i=1;i<=n;i++)
    {
        sum/=2;
        printf("%d ",(sum)+1);
    }
    return 0;
}
