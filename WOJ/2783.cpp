/****************************************
 *  -> W2783:Offline
 *     W2784:Online
 * !!! This is an experimental program!!!
 * !!!And it's STD!!!
 ****************************************/

#include <cstdio>
#include <algorithm>
#include <set>

using std::set;
using std::swap;

const int N=5233,M=12;

class LCT //wtf
{
public:
    struct Node
    {
        Node *ch[2],*f;
        int size,isize,rev;
        Node()
        {
            size=1;
            isize=0;
            ch[0]=ch[1]=f=0;
        }
    }a[N];

    void up(Node *x)
    {
        x->size=(x->ch[0]?x->ch[0]->size:0)+(x->ch[1]?x->ch[1]->size:0)+x->isize+1;
    }

    int isL(Node *x)
    {
        return !x->f||(x->f->ch[0]!=x && x->f->ch[1]!=x);
    }

    int dir(Node *x)
    {
        return x->f && x->f->ch[1]==x;
    }

    void rotate(Node *x)
    {
        Node *y=x->f,*z=y->f;
        int wh=dir(x);
        if(!isL(y))
        {
            z->ch[dir(y)]=x;
        }
        x->f=z;
        if(y->ch[wh]=x->ch[wh^1])
        {
            y->ch[wh]->f=y;
        }
        (x->ch[wh^1]=y)->f=x;
        up(y);
        up(x);
    }

    void push(Node *x)
    {
        if(!x || !x->rev) return;
        swap(x->ch[0],x->ch[1]);
        if(x->ch[0]) x->ch[0]->rev^=1;
        if(x->ch[1]) x->ch[1]->rev^=1;
        x->rev=0;
    }

    void pushtop(Node *x)
    {
        if(!isL(x))
            pushtop(x->f);
        push(x);
    }

    void splay(Node *x)  //You have been splayed.
    {
        pushtop(x);
        for(;!isL(x);rotate(x))
            if(!isL(x->f))
                rotate((dir(x)^dir(x->f))?x:x->f);
    }

    void access(Node *x)
    {
        for(Node *t=0;x;x=x->f)
        {
            splay(x);
            x->isize-=t?t->size:0;
            x->isize+=x->ch[1]?x->ch[1]->size:0;
            x->ch[1]=t;
            t=x;
            up(x);
        }
    }

    void rev(Node *x)
    {
        access(x);
        splay(x);
        x->rev^=1;
    }

    int size(int u)
    {
        Node *x=a+u;
        rev(x);
        return x->size;
    }

    void link(int u,int v)
    {
        Node *x=a+u,*y=a+v;
        rev(y);
        rev(x);
        x->f=y;
        y->isize+=x->size;
        access(x);
    }

    void cut(int u,int v)
    {
        Node *x=a+u,*y=a+v;
        rev(x);
        access(y);
        splay(y);
        y->ch[0]=x->f=0;
        up(y);
    }

    int vlink(int u,int v)
    {
        Node *x=a+u,*y=a+v;
        rev(x);
        access(y);
        splay(y);
        while(y->ch[0])
            y=y->ch[0];
        return x==y;
    }
};

class DymGraph
{
private:
    LCT fst[M+2];
    set <int> iT[M+2][N],nT[M+2][N];
public:
    void ln(int u,int v)
    {
        if(fst[0].vlink(u,v))
        {
            nT[0][u].insert(v);
            nT[0][v].insert(u);
        }
        else
        {
            fst[0].link(u,v);
            iT[0][u].insert(v);
            iT[0][v].insert(u);
        }
    }
    void dfs(int lev,int u,int v,int fa,bool &f)
    {
        for(int i=lev+1;i<M;i++)
        {
            for(int t:iT[i][u])
            {
                if(t!=fa) dfs(lev,t,v,u,f);
            }
        }
        set <int> ::iterator i=iT[lev][u].begin();
        while(i!=iT[lev][u].end() && !f)
        {
            int cur=*i;
            iT[lev][u].erase(i++);
            iT[lev][cur].erase(u);
            fst[lev+1].link(u,cur);
            iT[lev+1][u].insert(cur);
            iT[lev+1][cur].insert(u);
            dfs(lev,cur,v,u,f);
        }
        i=nT[lev][u].begin();
        while(i!=nT[lev][u].end() && !f)
        {
            int cur=*i;
            nT[lev][u].erase(i++);
            nT[lev][cur].erase(u);
            if(fst[lev].vlink(cur,v))
            {
                iT[lev][cur].insert(u);
                iT[lev][u].insert(cur);
                for(int j=0;j<=lev;j++)
                {
                    fst[j].link(cur,u);
                }
                f=1;
            }
            else
            {
                nT[lev+1][cur].insert(u);
                nT[lev+1][u].insert(cur);
            }

        }
    }

    void fix(int lev,int u,int v)
    {
        bool f=0;
        for(int i=lev;~i;i--)
        {
            if(fst[i].size(u)>fst[i].size(v))
            {
                swap(u,v);
            }
            dfs(i,u,v,0,f);
            if(f) break;
        }
    }

    void cut(int u,int v)
    {
        int lev;
        for(lev=0;lev<M;lev++)
        {
            if(nT[lev][u].count(v))
            {
                nT[lev][u].erase(v);
                nT[lev][v].erase(u);
                return ;
            }
            else if(iT[lev][u].count(v))
            {
                iT[lev][u].erase(v);
                iT[lev][v].erase(u);
                break;
            }
            for(int i=0;i<=lev;i++)
            {
                fst[i].cut(u,v);
            }
            fix(lev,u,v);
        }
    }

    bool vlink(int u,int v)
    {
        return fst[0].vlink(u,v);
    }
}g;

int n,m,lst;

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d",&n,&m);
    while(m--)
    {
        int op,u,v;
        scanf("%d %d %d",&op,&u,&v);
        if(op==0)
        {
            g.ln(u,v);
        }
        if(op==1)
        {
            g.cut(u,v);
        }
        if(op==2)
        {
            if(g.vlink(u,v))
            {
                lst=u;
            }
            printf("%c\n",(lst==u)?'Y':'N');
        }
    }
    return 0;
}
