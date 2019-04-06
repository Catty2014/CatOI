/* WOJ #3821 剪花布条
 * KMP
 * Template
 */

#include <cstdio>
#include <cstring>

char P[1333],T[1333];

int nxt[1333];
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
    while(scanf("%s",&P) && P[0]!='#' && scanf("%s",&T)){
        _l1=strlen(P);
        _l2=strlen(T);
        c_nxt();
        printf("%d\n",KMP()); 
    }
    return 0;
}