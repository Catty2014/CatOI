
//Code for transmission
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

typedef unsigned int uint;

std::queue <int> q;//Total Cards
struct Player
{
    int place;
    int deltaPlace;
    std::vector <int> card;
    int type;
    int showType;
    int hp;
    int hasBow;
}p[8];
int n;
int al[5];

int mpl[256];
int mpr[10];
int gameOverD=0;

void init()
{
    mpl[(int)'K']=1;
    mpl[(int)'D']=2;
    mpl[(int)'P']=3;
    mpl[(int)'F']=4;
    mpl[(int)'N']=5;
    mpl[(int)'W']=6;
    mpl[(int)'J']=7;
    mpl[(int)'Z']=8;
    mpr[1]='K';
    mpr[2]='D';
    mpr[3]='P';
    mpr[4]='F';
    mpr[5]='N';
    mpr[6]='W';
    mpr[7]='J';
    mpr[8]='Z';
}

void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char s[233];
        scanf("%s",s);
        switch(s[0])
        {
        case 'M':
            {
                p[i].type=1;
                al[1]++;
                break;
            }

        case 'Z':
            {
                p[i].type=2;
                al[2]++;
                break;
            }

        case 'F':
            {
                p[i].type=3;
                al[3]++;
                break;
            }
        }
        for(int j=3;j<=(int)strlen(s)-1;j++)
        {
            if(s[j]!=32) p[i].card.push_back(mpl[(int)s[j]]);
        }
    }
    char s[555];
    scanf("%s",s);
    for(int i=0;i<=(int)strlen(s)-1;i++)
    {
        if(s[i]!=32) q.push(mpl[(int)s[i]]);
    }
}

void kill(int u,int v);
void save(int u);

void cardK(int u)
{
    /* for(int ) */
}

void cardP(int u)
{
    int req=4-p[u].hp;
    if(req==0) return;
    for(uint i=1;i<=p[u].card.size();i++)
    {
        if(p[u].card[i]==3)
        {
            req--;
            p[u].card.erase(p[u].card.begin()+i);
            p[u].hp++;
        }
        if(req==0) return;
    }
    return ;
}

void cardZ(int u)
{
    if(p[u].hasBow==1) return;
    for(uint i=1;i<=p[u].card.size();i++)
    {
        if(p[u].card[i]==8)
        {
            p[u].card.erase(p[u].card.begin()+i);
            p[u].hasBow=1;
            return;
        }
    }
}

void save(int u)
{
    int req=1-p[u].hp;
    for(uint i=1;i<=p[u].card.size();i++)
    {
        if(p[u].card[i]==3)
        {
            req--;
            p[u].card.erase(p[u].card.begin()+i);
            p[u].hp++;
        }
        if(req==0) return;
    }
    return ;
}

void damage(int u,int v,int f)
{
    p[v].hp--;
    if(p[u].type==1&&(f==5||f==6)) p[v].showType=2;
    if(p[v].hp==0)
    {
        save(v);
    }
    if(p[v].hp==0)
    {
        kill(u,v);
    }
}

int atkDef(int u,int v,int t,int f)
{
    if(p[v].type==2&&p[u].type==1&&t==1&&f==4)
    {
        damage(u,v,f);
        return 0;
    }
    for(uint i=1;i<=p[v].card.size();i++)
    {
        if(p[v].card[i]==t) 
        {
            p[v].card.erase(p[v].card.begin()+i);
            return 1;
        }
    }
    damage(u,v,f);
    return 0;
}

void getCard(int pl,int t)
{
    for(int i=1;i<=t;i++)
    {
        p[pl].card.push_back(q.front());
        q.pop();
    }
}

void clrCard(int u)
{
    p[u].card.clear();
    p[u].hasBow=0;
}

void gameOver(int ty)
{
    printf("%s\n",(ty==1)?"MP":"FP");
    for(int i=1;i<=n;i++)
    {
        if(p[i].hp==-1) printf("DEAD\n");
        else
        {
            for(uint j=1;j<=p[i].card.size();j++)
            {
                printf("%d ",p[i].card[j]);
            }
        }
    }
    gameOverD=1;
    return ;
}

void kill(int u,int v)
{
    ///u-->v
    clrCard(v);
    p[v].hp=-1;
    if(p[v].type==3)
    {
        getCard(u,3);
    }
    if(p[v].type==2&&p[u].type==1)
    {
        clrCard(u);
    }
    al[p[v].type]--;
    if(al[p[v].type]==0)
    {
        if(p[v].type==1) gameOver(0);
        if(p[v].type==3) gameOver(1);
    }
    for(int i=v+n;i>=1;i--)
    {
        int pl=i%n;
        if(pl==0) pl=n;
        if(p[pl].hp>0) 
        {
            p[pl].deltaPlace++;
            break;
        }
    }
    return ;
}


void play()
{
    for(int i=1;;i++)
    {
        if(gameOverD==1) break;
        int pl=i%n;
        if(pl==0) pl=n;
        getCard(pl,2);

    }
    return ;
}

int main()
{
    init();
    read();
    play();
    return 0;
}
