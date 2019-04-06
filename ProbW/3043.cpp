#include <cstdio>

int main()
{
    int p,e,i,d,_case=0,ans;
    while(1)
    {
        scanf("%d %d %d %d",&p,&e,&i,&d);
        if(p==-1) return 0;
        int lcm=23*28*33;
		ans=(5544*p+14421*e+i*1288-d+lcm)%lcm;
        if(ans==0) ans=lcm;
        printf("Case %d: the next triple peak occurs in %d days.\n",++_case,ans);
    }
}