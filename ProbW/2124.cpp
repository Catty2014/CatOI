/* WOJ #2124 子串查找
 * KMP
 * Template
 */

#include <cstdio>
#include <cstring>

char P[133333],T[133333];

int nxt[133333];
int _l1,_l2;
void c_nxt()
{
    nxt[0]=-1;
    int k=-1;
    for (int q=1;q<_l2;++q) //0 is unavaliable
    {
        while(k>-1&T[k+1]!=T[q])
        {
            k=nxt[k];
        }
        if(T[k+1]==T[q])
        {
            k++;
        }
        nxt[q]=k;
    }
    return ;
}

int KMP()
{
    int k=-1;
    int ans=0;
    for(int i=0;i<_l1;i++)
    {
        while(k>-1&&T[k+1]!=P[i])
        {
            k=nxt[k];
        }
        if(T[k+1]==P[i])
        {
            k++;
        }
        if(k==_l2-1)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    scanf("%s",&T);
    scanf("%s",&P);
    {
        _l1=strlen(T);
        _l2=strlen(P);
        c_nxt();
        printf("%d\n",KMP()); 
    }
    return 0;
}