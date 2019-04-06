/****************************************
 * W1749 树的统计
 * 树链剖分
 * (完成中)
 ****************************************/

#include <cstdio>

//DFS1:找边，建树，并统计
void d1(int f)
{
    siz[f]=1;
    hs[f]=0;
    for(int i=fi[f];i;i=e[i].nxt)
    {
        if(e[i].v==fa[f]) continue;
        int &son=e[i].v;
        dep[son]=dep[f]+1;
        fa[son]=f;
        d1(son);
        siz[f]+=siz[son];
    }
}

int main()
{

}