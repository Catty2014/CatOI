#include <cstdio>

// int FindOutlier(std::vector<int> a)
// {
//   int result=0;
//   int odd=0;
//   for(int i=1;i<=a.size();i++)
//   {
//     if(a[i]%2==1) odd++;
//   }
//   if(odd==1)
//   {
//     for(int i=1;i<=a.size();i++)
//     {
//       if(a[i]%2==1) result=a[i];
//     }
//   }
//   else
//   {
//     for(int i=1;i<=a.size();i++)
//     {
//       if(a[i]%2==0) result=a[i];
//     }

//   }
//   return result;
// }
int n;
int a[2333];

int liar()
{
    int result = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1)
            odd++;
    }
    if (odd == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 1)
                result = a[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 0)
                result = a[i];
        }
    }
    return result;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", liar());
    return 0;
}