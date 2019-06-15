/****************************************
 * W3706 最假女选手
 * Segment Tree(Cross) Violence
 ****************************************/

#include<cstdio>

int n;
int a[523333];
int m;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r);
        int x;
        if(op<=3) scanf("%d",&x);
        if(op==1)
        {
            for(int j=l;j<=r;j++)
            {
                a[j]+=x;
            }
        }
        if(op==2)
        {
            for(int j=l;j<=r;j++)
            {
                if(a[j]<x) a[j]=x;
            }
        }
        if(op==3)
        {
            for(int j=l;j<=r;j++)
            {
                if(a[j]>x) a[j]=x;
            }
        }
        if(op==4)
        {
            int ans=0;
            for(int j=l;j<=r;j++)
            {
                ans+=a[j];
            }
            printf("%d\n",ans);
        }
        if(op==5)
        {
            int ans=0x80000000;
            for(int j=l;j<=r;j++)
            {
                if(ans<a[j]) ans=a[j];
            }
            printf("%d\n",ans);
        }
        if(op==6)
        {
            int ans=0x7fffffff;
            for(int j=l;j<=r;j++)
            {
                if(ans>a[j]) ans=a[j];
            }
            printf("%d\n",ans);
        }
    }
}