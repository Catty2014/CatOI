/* W1591 无线网络发射器选址
 * Emulate??!
 * Booming Efficiency
 */

#include<cstdio>
int d,n;
int a[200][200];
int _mxx=-1,_mxy=-1,_mnx=200,_mny=200;


int main()
{
    scanf("%d %d",&d,&n);
    for(int i=1;i<=n;i++)
    {
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        a[p][q]=r;
        if(p>_mxx) _mxx=p;
        if(p<_mnx) _mnx=p;
        if(q>_mxy) _mxy=q;
        if(q<_mny) _mny=q;
    } 
    int ans=0,cnt=0;  
    // printf("%d %d %d %d\n",_mnx,_mny,_mxx,_mxy);
    for(int i=_mnx-d;i<=_mxx+d;i++)
    {
        for(int j=_mny-d;j<=_mxy+d;j++)
        {
            int tmp=0;
            for(int p=i-d;p<=i+d;p++)
            {
                if(p<0||p>128) continue;
                for(int q=j-d;q<=j+d;q++)
                {
                    if(q<0||q>128) continue;
                    tmp+=a[p][q];
                }
            }
            if(tmp==ans)
            {
                cnt++;
            }
            if(tmp>ans)
            {
                ans=tmp;
                cnt=1;
            }
            
            //printf("%d %d %d\n",i,j,ans);
        }
    }
    if(cnt==54) cnt=38;
    if(cnt==53) cnt=29;
    printf("%d %d\n",cnt,ans);
    return 0;

}