#include <cstdio>
#include <queue>

const int PN=12;

int playerTotal,cardTotal;
int gameOverD=0;
int cardIsEmpty=0;

class Card
{
    int a[1023];
    int cnt;
public:
    void push(int x)
    {
        a[++cnt]=x;
    }
    int find(int x)
    {
        for(int i=1;i<=cnt;i++)
        {
            if(a[i]==x) return i;
        }
        return 0;
    }
    void del(int x)
    {
        int pl=find(x);
        for(int i=pl+1;i<=cnt;i++)
        {
            a[i-1]=a[i];
        }
        cnt--;
        if(cnt<=0) cnt=0;
        a[cnt+1]=0;
    }
    void clear()
    {
        for(int i=1;i<=cnt;i++)
        {
            a[i]=0;
        }
        cnt=0;
    }
    int size()
    {
        return cnt;
    }
    int operator[](int k)
    {
        return a[k];
    }
};
struct Player
{
    int id;
    //Hit-point of each player
    int hp;
    //If has pig-bow
    int hasBow;
    //Cards
    /* std::vector <int> cards; */
    Card c;
    //Type of player
    //1:MP
    //2.ZP
    //3.FP
    int type;
    //Type of player showing:
    //1.MP
    //2.reallyZP
    //3.likeFP
    //4.reallyFP
    int showType;
    int nextPlayer;
    int lastPlayer;
    int atkUsed;
}p[PN];
int playerCount[PN];//1:MP,2:ZP,3:FP

std::queue <int> c;//Cards int heap

int mpl[256],mpr[12];

void initCardMap()
{
    mpl[(int)'K']=1; //Kill
    mpl[(int)'D']=2; //Defence
    mpl[(int)'P']=3; //Peach
    mpl[(int)'F']=4; //Fight
    mpl[(int)'N']=5; //NMRQ
    mpl[(int)'W']=6; //WJQF
    mpl[(int)'J']=7; //Ctrl-Z
    mpl[(int)'Z']=8; //Pig-Bow
    mpr[1]='K';
    mpr[2]='D';
    mpr[3]='P';
    mpr[4]='F';
    mpr[5]='N';
    mpr[6]='W';
    mpr[7]='J';
    mpr[8]='Z';
}


void getCard(int pl,int cnt)
{
    for(int i=1;i<=cnt;i++)
    {
        int cd=0;
        if(cardIsEmpty==0)
        {
            cd=c.front();
            c.pop();
            if(c.size()==1) cardIsEmpty=1;
            p[pl].c.push(cd);
        }
        else
        {
            cd=c.front();
            p[pl].c.push(cd);
        }
        /* printf("%dgot%d\n",pl,cd); */
    }
}

void deleteAllCard()
{
    p[1].c.clear();
    p[1].hasBow=0;
}

void gameOver()
{
    printf("%s\n",(p[1].hp<=0)?"FP":"MP");
    for(int i=1;i<=playerTotal;i++)
    {
        /* printf("%d ",p[i].hp); */
        if(p[i].hp<=0) printf("DEAD\n");
        else
        {
            for(int j=1;j<=p[i].c.size();j++)
            {
                printf("%c ",mpr[p[i].c[j]]);
            }
            printf("\n");
        }
    }
    /* printf("\n\n"); */
    /* printf("%lu\n",c.size()); */
}
void playerDied(int src,int pl);
int hasCard(int pl,int cc);
int useCard(int pl,int cc);

int judgeDeath(int pl)
{
    if(p[pl].hp<=0)
    {
        while(p[pl].c.find(3)&&p[pl].hp<=0)
        {
            p[pl].c.del(3);
            p[pl].hp++;
        }
    }
    return (p[pl].hp<=0);
}

void playerDied(int src,int pl)
{
    if(p[pl].type==1)
    {
        gameOverD=1;
    }
    if(p[pl].type==2)
    {
        playerCount[2]--;
        if(p[src].type==1)deleteAllCard();
    }
    if(p[pl].type==3)
    {
        playerCount[3]--;
        if(playerCount[3]&&src!=pl) getCard(src,3);
        else
        {
            gameOverD=1;
        }
    }
    p[p[pl].lastPlayer].nextPlayer=p[pl].nextPlayer;
    p[p[pl].nextPlayer].lastPlayer=p[pl].lastPlayer;
}

int healing(int pl)
{
    if(p[pl].hp==4) return 0;
    p[pl].hp++;
    return 1;
}

int pigbow(int pl)
{
    p[pl].hasBow=1;
    return 1;
}

int queryAtk(int pl)
{
    if(p[pl].c.find(1))
    {
        p[pl].c.del(1);
        return 1;
    }
    return 0;
}

int queryDef(int pl)
{
    if(p[pl].c.find(2))
    {
        p[pl].c.del(2);
        return 1;
    }
    return 0;
}

int queryVul(int src,int tg,int ps)
{
    int res=0;
    for(int i=src;i<=src+playerTotal;i++)
    {
        int pl=i;
        if(pl>playerTotal) pl-=playerTotal;
        if(p[pl].hp<=0) continue;
        if(p[pl].c.find(7))
        {
            if(ps==1)
            {
                if(p[tg].type==1)
                {
                    if(p[pl].type==1||p[pl].type==2)
                    {
                        if(p[pl].type==2) p[pl].showType=2;
                        res=1;
                        p[pl].c.del(7);
                        res-=queryVul(pl,pl,0);
                        break;
                    }
                }
                if(p[tg].showType==2)
                {
                    if(p[pl].type==1||p[pl].type==2)
                    {
                        if(p[pl].type==2) p[pl].showType=2;
                        res=1;
                        p[pl].c.del(7);
                        res-=queryVul(pl,pl,0);
                        break;
                    }
                }
                if(p[tg].showType==4)
                {
                    if(p[pl].type==3)
                    {
                        p[pl].showType=4;
                        res=1;
                        p[pl].c.del(7);
                        res-=queryVul(pl,pl,0);
                        break;
                    }
                }
            }
            if(ps==0)
            {
                if(p[tg].showType==1||p[tg].showType==2)
                {
                    if(p[pl].type==3)
                    {
                        p[pl].showType=4;
                        res=1;
                        p[pl].c.del(7);
                        res-=queryVul(pl,pl,0);
                        break;
                    }
                }
                if(p[tg].showType==4)
                {
                    if(p[pl].showType==1||p[pl].type==2)
                    {
                        if(p[pl].type==2) p[pl].showType=2;
                        res=1;
                        p[pl].c.del(7);
                        res-=queryVul(pl,pl,0);
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int fight(const int pl)
{
    //Part1:Search Object
    int tg=0;
    switch(p[pl].type)
    {
    case 1:
        {
            int vtg=pl;
            while(p[vtg].showType<=2)
            {
                vtg=p[vtg].nextPlayer;
                if(vtg==pl)
                {
                    return 0;
                }
            }
            tg=vtg;
            break;
        }
    case 2:
        {
            int vtg=pl;
            while(p[vtg].showType<=3)
            {
                vtg=p[vtg].nextPlayer;
                if(vtg==pl)
                {
                    return 0;
                }
            }
            tg=vtg;
            break;
        }
    case 3:
        {
            int vtg=pl;
            while(p[vtg].showType!=1)
            {
                vtg=p[vtg].nextPlayer;
                if(vtg==pl)
                {
                    break;
                }
            }
            if(vtg!=pl)
            {
                tg=vtg;
                break;
            }
            while(p[vtg].showType!=2)
            {
                vtg=p[vtg].nextPlayer;
                if(vtg==pl)
                {
                    return 0;
                }
            }
            tg=vtg;
            break;
        }
    }
    if(p[tg].showType==1||(p[tg].showType==2&&p[pl].showType!=1))
    {
        p[pl].showType=4;
    }
    if(p[tg].showType==4&&p[pl].showType!=1)
    {
        p[pl].showType=2;
    }
    while(1)
    {
        if(queryVul(pl,tg,1)==1) break;
        if(queryAtk(tg)==0||p[tg].type==2)
        {
            p[tg].hp--;
            if(judgeDeath(tg)) playerDied(pl,tg);
            break;
        }
        /* if(queryVul(pl,pl,1)==1) break; */
        if(queryAtk(pl)==0)
        {
            p[pl].hp--;
            if(judgeDeath(pl)) playerDied(tg,pl);
            break;
        }
    }
    return 1;
}

int attack(int pl)
{
    if(p[pl].atkUsed==1&&p[pl].hasBow==0) return 0;
    /* printf("Attack:%d\n",pl); */
    int tg=p[pl].nextPlayer;
    if(p[pl].type==1)
    {
        if(p[tg].showType<=2||p[tg].showType==0) return 0;
    }
    if(p[pl].type==2)
    {
        if(p[tg].showType<=3||p[tg].showType==0) return 0;
    }
    if(p[pl].type==3)
    {
        if(p[tg].showType>=3||p[tg].showType==0) return 0;
    }
    /* printf("Target:%d\n",tg); */
    p[pl].atkUsed=1;
    if(p[tg].type==1||p[tg].showType==2)
    {
        p[pl].showType=4;
    }
    if(p[pl].type!=1&&p[tg].showType==4)
    {
        p[pl].showType=2;
    }
    if(queryDef(tg)==0)
    {
        p[tg].hp--;
        if(judgeDeath(tg)) playerDied(pl,tg);
    }
    return 1;
}

int WJQF(int pl)
{
    for(int ii=pl+1;ii<pl+playerTotal;ii++)
    {
        if(gameOverD==1) break;
        int dmg=1;
        int i=ii;
        if(i>playerTotal) i-=playerTotal;
        if(p[i].hp<=0) continue;
        dmg-=queryVul(pl,i,1);
        if(dmg==1)dmg-=queryDef(i);
        if(dmg==1)
        {
            p[i].hp--;
            if(p[i].type==1 && p[pl].showType==0)
            {
                p[pl].showType=3;
            }
        }
        if(judgeDeath(i)) playerDied(pl,i);
    }
    return 1;
}

int NMRQ(int pl)
{
    for(int ii=pl+1;ii<pl+playerTotal;ii++)
    {
        if(gameOverD==1) break;
        int dmg=1;
        int i=ii;
        if(i>playerTotal) i-=playerTotal;
        if(p[i].hp<=0) continue;
        dmg-=queryVul(pl,i,1);
        if(dmg==1)dmg-=queryAtk(i);
        if(dmg==1)
        {
            p[i].hp--;
            if(p[i].type==1 && p[pl].showType==0)
            {
                p[pl].showType=3;
            }
        }
        if(judgeDeath(i)) playerDied(pl,i);
    }
    return 1;
}
int useCard(int pl,int cc)
{
    switch(cc)
    {
    case 3:
        return healing(pl);
    case 8:
        return pigbow(pl);
    case 5:
        return NMRQ(pl);
    case 6:
        return WJQF(pl);
    case 4:
        return fight(pl);
    case 1:
        return attack(pl);
    }
    return 0;
}

void setCard(int pl)
{
    int can_have_operation=0;
    while((p[pl].c.size()!=0&&can_have_operation<=2)||gameOverD==1)
    {
        if(gameOverD==1)
        {
            gameOver();
            return;
        }
        if(p[pl].hp<=0) break;
        /* gameOver(); */
        for(int i=1;i<=p[pl].c.size();i++)
        {
            int cc=p[pl].c[i];
            if(useCard(pl,cc))
            {
                p[pl].c.del(cc);
                can_have_operation--;
                break;
            }
        }
        can_have_operation++;
    }
    return;
}

void gamePlay()
{
    for(int i=1;;i++)
    {
        if(gameOverD==1) return;
        int pl=i;
        while(pl>playerTotal) pl-=playerTotal;
        if(p[pl].hp<=0) continue;
        getCard(pl,2);
        /* printf("Player#%d,round#%d:Got Card\n",pl,i); */
        /* gameOver(); */
        setCard(pl);
        /* printf("Player#%d:Used Card\n",pl); */
        /* gameOver(); */
        p[pl].atkUsed=0;
    }
}

void readData()
{
    scanf("%d %d",&playerTotal,&cardTotal);
    for(int i=1;i<=playerTotal;i++)
    {
        char s[20];
        scanf("%s",s);
        if(s[0]=='M')
        {
            p[i].type=1;
            p[i].showType=1;
            playerCount[1]++;
        }
        if(s[0]=='Z')
        {
            p[i].type=2;
            p[i].showType=0;
            playerCount[2]++;
        }
        if(s[0]=='F')
        {
            p[i].type=3;
            p[i].showType=0;
            playerCount[3]++;
        }
        p[i].id=i;
        p[i].nextPlayer=(i+1)%playerTotal;
        p[i].lastPlayer=(i-1)%playerTotal;
        if(p[i].nextPlayer==0) p[i].nextPlayer=playerTotal;
        if(p[i].lastPlayer==0) p[i].lastPlayer=playerTotal;
        p[i].hp=4;
        for(int j=1;j<=4;j++)
        {
            char s[5];
            scanf("%s",s);
            p[i].c.push(mpl[(int)s[0]]);
        }
    }
    for(int i=1;i<=cardTotal;i++)
    {
        char s[5];
        scanf("%s",s);
        c.push(mpl[(int)s[0]]);
    }
}

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    initCardMap();
    readData();
    gamePlay();
    return 0;
}

