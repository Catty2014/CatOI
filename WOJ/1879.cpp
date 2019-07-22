#include <cstdio>

int main(int argc, char const *argv[])
{
    int tp;
    while(1){
        scanf("%d",&tp);
        if(tp==0) break;
        int maxt=-1,day=0;
        for(int i=1;i<=tp;i++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            if(p+q>maxt&&p+q>8)
            {
                day=i;
                maxt=p+q;
           }
    }
    printf("%d\n",day);
    }
    return 0;
}
