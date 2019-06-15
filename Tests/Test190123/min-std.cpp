#include<cstdio>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    n-=1;
    m-=1;
    if(n%m==0) printf("%d",n/m);
    else printf("%d",n/m+1);
    return 0; 
}