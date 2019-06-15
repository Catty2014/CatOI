#include<cstdio>
using namespace std;
int main()
{
    int n,stack[102000],a[102000];
    bool fail=0;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        int top=0,bh=1;
        for (int i=1;i<=n;i++)
        {
            while (bh<=a[i])
            {
                stack[++top]=bh;
                bh++;
            }
            if (stack[top]==a[i]) top--;
            else
            {
                fail=1;
            }
        }
        if (fail==0) printf("Y\n");
        else printf("J\n");
        fail=0;
    }
    
}
/*
--------------------- 
作者：SSLGZ_yyc 
来源：CSDN 
原文：https://blog.csdn.net/SSLGZ_yyc/article/details/81698023 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/