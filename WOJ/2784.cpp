/****************************************
 *  -> W2783:Offline
 *     W2784:Online
 * !!! This is an experimental program!!!
 * !!!And it's STD!!!
 ****************************************/

#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N=5010,M=12;

int ttt;

char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

void read(int &x)
{
    char c=nc();
    x=0;
    for(; c>'9'||c<'0'; c=nc()) {};
    for(; c>='0'&&c<='9'; x=x*10+c-'0',c=nc()) {};
}

struct LCT
{
    struct node
    {
        node *ch[2],*f;
        int size,isize,rev;
        node()
        {
            size=1;
            isize=0;
            ch[0]=ch[1]=f=0;
        }
    } a[N];

    void Up(node *x)
    {
        x->size=(x->ch[0]?x->ch[0]->size:0)+(x->ch[1]?x->ch[1]->size:0)+x->isize+1;
    }

    int isl(node *x)
    {
        return !x->f || (x->f->ch[0]!=x && x->f->ch[1]!=x);
    }
    int dir(node *x)
    {
        return x->f && x->f->ch[1]==x;
    }

    void rot(node *x)
    {
        node *y=x->f,*z=y->f;
        int wh=dir(x);
        if(!isl(y))
            z->ch[dir(y)]=x;
        x->f=z;
        if(y->ch[wh]=x->ch[wh^1])
            y->ch[wh]->f=y;
        (x->ch[wh^1]=y)->f=x;
        Up(y);
        Up(x);
    }

    void Push(node *x)
    {
        if(!x || !x->rev)
            return ;
        swap(x->ch[0],x->ch[1]);
        if(x->ch[0])
            x->ch[0]->rev^=1;
        if(x->ch[1])
            x->ch[1]->rev^=1;
        x->rev=0;
    }

    void Pushtop(node *x)
    {
        if(!isl(x))
            Pushtop(x->f);
        Push(x);
    }

    void splay(node *x)
    {
        Pushtop(x);
        for(; !isl(x); rot(x))
            if(!isl(x->f))
                rot((dir(x)^dir(x->f))?x:x->f);
    }

    void access(node *x)
    {
        for(node *t=0; x; x=x->f)
        {
            splay(x);
            x->isize-=t?t->size:0;
            x->isize+=x->ch[1]?x->ch[1]->size:0;
            x->ch[1]=t;
            t=x;
            Up(x);
        }
    }

    void reverse(node *x)
    {
        access(x);
        splay(x);
        x->rev^=1;
    }

    int Size(int u)
    {
        node *x=a+u;
        reverse(x);
        return x->size;
    }

    void link(int u,int v)
    {
        node *x=a+u,*y=a+v;
        reverse(y);
        reverse(x);
        x->f=y;
        y->isize+=x->size;
        access(x);
    }

    void cut(int u,int v)
    {
        node *x=a+u,*y=a+v;
        reverse(x);
        access(y);
        splay(y);
        y->ch[0]=x->f=0;
        Up(y);
    }

    int linked(int u,int v)
    {
        node *x=a+u,*y=a+v;
        reverse(x);
        access(y);
        splay(y);
        while(y->ch[0])
            y=y->ch[0];
        return x==y;
    }
};

namespace DG
{
LCT fst[M+2];
set<int> iT[M+2][N],nT[M+2][N];

void link(int u,int v)
{
    if(fst[0].linked(u,v))
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
    for(int i=lev+1; i<M; i++)
    {
        for(int t : iT[i][u])
            if(t!=fa)
                dfs(lev,t,v,u,f);
    }
    set<int>::iterator i=iT[lev][u].begin();
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
        if(fst[lev].linked(cur,v))
        {
            iT[lev][cur].insert(u);
            iT[lev][u].insert(cur);
            for(int j=0; j<=lev; j++)
                fst[j].link(cur,u);//f=fst[j].linked(cur,u);
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
    for(int i=lev; ~i; i--)
    {
        if(fst[i].Size(u)>fst[i].Size(v))
            swap(u,v);
        dfs(i,u,v,0,f);
        if(f)
            break;
    }
}

void cut(int u,int v)
{
    int lev;
    for(lev=0; lev<M; lev++)
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
    }
    for(int i=0; i<=lev; i++)
        fst[i].cut(u,v);
    fix(lev,u,v);
}

bool linked(int u,int v)
{
    return fst[0].linked(u,v);
}
}

int n,m,lst;

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    read(n);    read(m);
    while(m--)
    {
        int opt,u,v;
        read(opt);read(u);read(v);
        /* u^=lst; */
        /* v^=lst; */
        if(opt==0)
            DG::link(u,v);
        else if(opt==1)
            DG::cut(u,v);
        else
        {
            if(DG::linked(u,v))
                lst=u;
            else
                lst=v;
            puts(lst==u?"Y":"N");
        }
    }
    return 0;
}
