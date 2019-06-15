#include<cstdio>

char a[113333],b[113333];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char p[130000],q[130000];
        scanf("%s %s",p,q);
        int da,db;
        for(int i=1;i<=100000;i++)
        {
            a[i]+=p[i]-'0';
            if(a[i]>=10)
            {
                a[i]-=10;
                da=1;
            }
            
        }
    }
}