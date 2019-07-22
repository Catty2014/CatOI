#include <cstdio>
const int N=100233;
const int M=N*22;
int n,m,t;
int s[M],lc[M],rc[M],r[N],nm[N];
void bd(int &rt,int l,int r)
{
    t++;
    rt=t;
    if(l==r)
    {
        s[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    bd(lc[rt],l,m);
    bd(rc[rt],m+1,r);
}

void ins(int p,int &nw,int l,int r,int pos,int v)
{
    t++;
    nw=t;
    if(l==r)
    {
        s[nw]=v;
        return;
    }
    lc[nw]=lc[p];
    rc[nw]=rc[p];
    int m=(l+r)>>1;
    if(pos<=m) ins(lc[p],lc[nw],l,m,pos,v);
    else       ins(rc[p],rc[nw],m+1,r,pos,v);
}
int qur(int rt,int l,int r,int pos)
{
    if(l==r) return s[rt];
    int m=(l+r)>>1;
    if(pos<=m) return qur(lc[rt],l,m,pos);
    else       return qur(rc[rt],m+1,r,pos);
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    n=N;
    scanf("%d",&m);
    t=nm[0]=0;
    bd(r[0],1,n);
    int t=0,c=0;
    for(int i=1;i<=m;i++)
    {
        char op[3];
        scanf("%s",op);
        switch(op[0]){
        case 'A' :
            {
                int v=0;
                scanf("%d",&v);
                ++t;
                ins(r[t-1],r[t],1,n,nm[t]=++c,v);
                break;
            }
        case 'Q' :
            {
                int x=0;
                scanf("%d",&x);
                printf("%d\n",qur(r[t],1,n,x));
                break;
            }
        case 'U' :
            {
                int x=0;
                scanf("%d",&x);
                int ls=t-x;
                ++t;
                r[t]=r[ls];
                nm[t]=c=nm[ls];
            }
        }
        //printf("%d %d\n",t,c);
    }
    return 0;
}
