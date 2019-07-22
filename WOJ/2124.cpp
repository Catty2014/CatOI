/* WOJ #2124 子串查找
 * KMP
 * Template
 */

#include <cstdio>
#include <cstring>

char P[1333333],T[1333333];

int nxt[1333333];
int _l1,_l2;
void c_nxt()
{
    nxt[0]=nxt[1]=0;
    int k=0;
    for (int q=1;q<_l2;q++) //0 is unavaliable
    {
        while(k>0&&T[k]!=T[q])
        {
            k=nxt[k];
        }
        if(T[k]==T[q])
        {
            k++;
        }
        nxt[q+1]=k;
    }
    return ;
}

int KMP()
{
    int k=0;
    int ans=0;
    for(int i=0;i<_l1;i++)
    {
        while(k>0&&T[k]!=P[i])
        {
            k=nxt[k];
        }
        if(T[k]==P[i])
        {
            k++;
        }
        if(k==_l2)
        {
            ans++;
            k=nxt[k];
        }
    }
    return ans;
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%s",T);
    scanf("%s",P);
    {
        _l1=strlen(T);
        _l2=strlen(P);
        /* printf("%d %d\n",_l1,_l2); */
        c_nxt();
        printf("%d\n",KMP()); 
    }
    return 0;
}
