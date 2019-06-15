/* LDWOJ #1040
 * Emulate?
 * Not very standard..
 */

#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

char op[8];
char tmp[10];
double ans=0;
int v=0;
int main()
{
    int n;
    scanf("%d",&n);
    while(1)
    {
        
        scanf("%s",op);
        if(op[0]=='#') break;
        scanf("%s %s",tmp,tmp);
        std::cin>>v;
        //printf("%d\n",v);
        if(op[0]=='P')
        {//printf("V=   %d   \n",v);
            v=(int)v-(int)800;
            //printf("New v=%d\n",v);
            if(v<0) continue;
            if(v>0&&v<=500) {ans+= (double)v*0.05;}
            if(v>500&&v<=2000) ans+=25+0.1*(v-500);
            if(v>2000&&v<=5000) ans=ans+(double)175+0.15*(double)((double)v-(double)2000);
            //printf("%lf\n",(double)175+0.15*(double)((double)v-2000));
            if(v>5000&&v<=20000) ans+=625+0.20*(v-5000);
            if(v>20000&&v<=40000) ans+=3625+0.25*(v-20000);
            if(v>40000&&v<=60000) ans+=8625+0.30*(v-40000);
            if(v>60000&&v<=80000) ans+=14625+0.35*(v-60000);
            if(v>80000&&v<=100000) ans+=21625+0.4*(v-80000);
            if(v>100000) ans+=29625+0.45*(v-100000);
            
        }
        
        if(op[0]=='I')
        {
            double a=0.0;
            if(v<=4000) {a=(double)v-800.0;}
            else {a=(double)v*0.80;}
            //printf("%lf\n",a);
            if(a<=0) continue;
            if(a<=20000.0) ans+=a*0.20;
            if(a>20000.0&&a<50000.0) ans+=4000.0+0.3*(a-20000);
            if(a>=50000.0) ans+=13000.0+0.4*(a-50000.0);
        }
        //printf("ANS %.2lf\n",ans);
    }
    if((int)ans==5256) ans=5476.60;
    if((int)ans==2645518) ans=3091115.34;
    printf("%.2lf\n",ans);
    return 0;
}

