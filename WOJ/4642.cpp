#include <cstdio>
#include <cstring>

struct Card
{
    int t,v,l,u;
}c[20],d[20];
int cn=0;

class Battle
{
private:
    int L[10][10];
    bool w[10];
public:
    void init()//Reset value to 0
    {
        memset(L,0,sizeof(L));
        memset(w,0,sizeof(w));
    }

    void addValue(int v,int l)//Add a new value in a line
    {
        L[l][++L[l][0]]=v;
    }

    int getValue(int k,int l)//Get sum value
    {
        if(w[l]==1)
        {
            return (k==0)?-1:L[l][0];
        }
        int ret=0;
        for(int i=1;i<=L[l][0];i++)
        {
            ret+=L[l][i];
        }
        return ret;
    }

    void changeWeather(int k,int l)//Change one's weather
    {
        w[l]=(k>0)?1:0;
    }

    bool getWeather(int l)//Get weather
    {
        return w[l];
    }

    void setBurn()//BURNING!
    {
        int mxx=-1000;
        int mxp=0;
        for(int j=1;j<=6;j++)
        {
            int mx=-1000;
            mxp=0;
            for(int i=1;i<=6;i++)
            {
                int var=getValue(0,i);
                if(var>mx)
                {
                    mx=var;mxp=i;
                }
            }
            if(mxx!=-1 && mxx!=mx)
            {
                return;
            }
            mxx=mx;
            L[mxp][0]=0;
        }
        return;
    }

    void setDouble(int l)
    {
        if(w[l]==0)
        {
            for(int i=1;i<=L[l][0];i++)
            {
                L[l][i]*=2;
            }
        }
    }

    int getDelta()
    {
        int val=0;
        for(int i=1;i<=3;i++)
        {
            val-=getValue(1,i);
        }
        for(int i=4;i<=6;i++)
        {
            val+=getValue(1,i);
        }
        return val;
    }
};

int nw;
int ans=-210700000;
int cnt=0;

void act(const Card c,Battle &p)
{
    switch(c.t)
    {
    case 1:
        {
            p.addValue(c.v,c.l);
            break;
        }
    case 2:
        {
            p.changeWeather(1,c.l);
            int opl=(c.l<=3)?c.l+3:c.l-3;
            p.changeWeather(1,opl);
            break;
        }
    case 3:
        {
            for(int i=1;i<=6;i++)
            {
                p.changeWeather(0,i);
            }
            break;
        }
    case 4:
        {
            p.setBurn();
        }
    }
}

int n,m;

void dfs(int m,int t,Battle s)
{
    if(t==n+1)
    {
        int tans=s.getDelta();
        if(tans==ans)
        {
            cnt++;
        }
        if(tans>ans)
        {
            cnt=1;
            ans=tans;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        Battle p=s;
        if(d[i].u==1) continue;
        for(int j=1;j<=n;j++)
        {
            if(d[j].t==d[i].t)
            {
                d[j].u=1;
            }
        }
        if(m==0)
        {
            if(d[i].t!=5)
            {
                act(d[i],p);
                act(c[t],p);
                dfs(m,t+1,p);
            }
            else
            {
                int val=0;
                for(int i=1;i<=6;i++)
                {
                    Battle q=p;
                    if(q.getWeather(i))
                    {
                        q.setDouble(i);
                        val=1;
                    }
                    else
                    {
                        continue;
                    }
                    act(c[t],q);
                    dfs(m,t+1,q);
                }
                if(val==0)
                {
                    act(c[t],p);
                    dfs(m,t+1,p);
                }
            }
        }
        if(m==1)
        {
            if(d[i].t!=5)
            {
                act(c[t],p);
                act(d[i],p);
                dfs(m,t+1,p);
            }
            else
            {
                int val=0;
                for(int i=1;i<=6;i++)
                {
                    Battle q=p;
                    act(c[t],q);
                    if(q.getWeather(i))
                    {
                        q.setDouble(i);
                        val=1;
                    }
                    else
                    {
                        continue;
                    }
                    dfs(m,t+1,q);
                }
                if(val==0)
                {
                    act(c[t],p);
                    dfs(m,t+1,p);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(d[j].t==d[i].t)
            {
                d[j].u=0;
            }
        }
    }
}


int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t>=3)
        {
            cn++;
            c[cn].t=t;
        }
        if(t==2)
        {
            cn++;
            c[cn].t=t;
            int l;
            scanf("%d",&l);
            c[cn].l=l+1;
        }
        if(t==1)
        {
            cn++;
            c[cn].t=t;
            int l,v;
            scanf("%d %d",&v,&l);
            c[cn].v=v;
            c[cn].l=l+1;
        }
    }
    cn=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t>=3)
        {
            cn++;
            d[cn].t=t;
        }
        if(t==2)
        {
            cn++;
            d[cn].t=t;
            int l;
            scanf("%d",&l);
            d[cn].l=l+4;
        }
        if(t==1)
        {
            cn++;
            d[cn].t=t;
            int l,v;
            scanf("%d %d",&v,&l);
            d[cn].v=v;
            d[cn].l=l+4;
        }
    }
    Battle none;
    none.init();
    dfs(m,1,none);
    printf("%d %d\n",ans,cnt);
    return 0;
}
