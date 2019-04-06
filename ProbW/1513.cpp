/*WOJ#1513 森林转二叉树
 *就是一道转树板子题
 *但是你要输出遍历序TM是什么鬼啊..
 */

#include <cstdio>
#include <map>

#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

int n;

std::map <char,int> M;

struct Tree
{
    int l;int r;
    int f;
    int v;
}t;//T:Tree

void dfs(int p,int d)
{
	if(d==1) printf("%d ",p);
	if(t.l) dfs(t.l,d);
	if(d==2) printf("%d ",p);
	if(t.r) dfs(t.r,d);
	if(d==3) printf("%d ",p);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char ch[3];
        scanf("%s",ch);
        M[ch[0]]=i;
        for(int j=1;j<=n;j++)
        {
            int kt;
            scanf("%d",&kt);
            if(kt==0) break;
            if()
        }
    }
}

