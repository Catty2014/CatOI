/* WOJ #1387 单词查找树(Tree)
 * Trie Tree
 * 60/100
 */

#include <cstdio>
#include <cstring>

#define debug() printf("233333\n")

int ldx(char c )  //Innocent ldx...
{
    return (int)(c-'A');
}

int chk[50000][100];
int size;
int val[6666];
char p[6666];

int insert(char c[]) //Incert and Query
{
    int len_c =strlen(c);
    int u=0;
    int ret=0;
    for(int i=0;i<len_c;i++)
    {
        int t=ldx(c[i]);
        if(chk[u][t]==0)
        {
            memset(chk[size],0,sizeof(chk[size]));
            val[size]=0;
            chk[u][t]=size++;
            ret++;
        }
        u=chk[u][t];
    }
    val[u]++;
    //printf("%d\n",size);
    //return ret;
    return size;
}

int main(int argc, char const *argv[])
{
    int ans=0;
    while(scanf("%s",p)!=EOF)
    {
        ans=insert(p);
    }
    printf("%d\n",ans);
    return 0;
}
