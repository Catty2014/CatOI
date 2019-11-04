#include <cstdio>
#include <vector>
#include <queue>

typedef unsigned int uint;

const int PN=12;
const int seq[15]={0,3,8,5,6,4,1};

int playerTotal,cardTotal;
int gameOverD=0;
int cardIsEmpty;
struct Player
{
    ///Hit-point of each player
    int hp;
    //Card count
    int card;
    //If has pig-bow
    int hasBow;
    //Cards
    std::vector <int> cards;
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
    int place;
    Player *nextPlayer;
    Player *lastPlayer;
    //1.Neutral
    //2.Friendly
    //3.Attactive
    int attitude[PN];
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


void getCard(int player,int count)
{
    for(int i=1;i<=count;i++)
    {
        if(cardIsEmpty==0)
        {
            int cd=c.front();
            c.pop();
            if(c.size()==1) cardIsEmpty=1;
            p[player].cards.push_back(cd);
        }
        else
        {
            int cd=c.front();
            p[player].cards.push_back(cd);
        }
    }
}

void deleteAllCard()
{
    p[1].cards.clear();
    p[1].hasBow=0;
}

void gameOver(int dd)
{
    printf("%s\n",(dd==1)?"FP":"MP");
    for(int i=1;i<=playerTotal;i++)
    {
        if(p[i].hp<=0) printf("DEAD\n");
        else
        {
            for(uint j=0;j<p[i].cards.size();j++)
            {
                printf("%c ",mpr[p[i].cards[j]]);
            }
            printf("\n");
        }
    }
}
void playerDied(int src,int pl);
int hasCard(int pl,int cc);
int useCard(int pl,int cc);

int judgeDeath(int pl)
{
    if(p[pl].hp<=0)
    {
        while(hasCard(pl,3)&&p[pl].hp<=0) useCard(pl,3);
    }
    return (p[pl].hp<=0);
}

void playerDied(int src,int pl)
{
    if(p[pl].type==1)
    {
        gameOverD=1;
        gameOver(1);
    }
    if(p[pl].type==2)
    {
        playerCount[2]--;
        if(p[src].type==1)deleteAllCard();
    }
    if(p[pl].type==3)
    {
        playerCount[3]--;
        if(playerCount[3])getCard(src,3);
        else
        {
            gameOver(3);
        }
    }
    p[pl].lastPlayer->nextPlayer=p[pl].nextPlayer;
}

int healing(int pl)
{
    p[pl].hp++;
    return 1;
}

int pigbow(int pl)
{
    p[pl].hasBow=1;
    return 1;
}

int WJQF(int pl)
{
    for(int i=pl+1;i<pl;i++)
    {
        if(i>playerTotal) i-=playerTotal;
        queryVul(pl,i);
        queryDef(pl,i);
        if(judgeDeath(i)) playerDied(pl,i);
    }
    return 1;
}

int NMRQ_Unfinished(int pl)
{
    for(int i=pl+1;i<pl;i++)
    {
        if(i>playerTotal) i-=playerTotal;
        queryVul(pl,i);
        queryAtk(pl,i);
        if(judgeDeath(i)) playerDied(pl,i);
    }
    return 1;
}

int hasCard(int pl,int cc)
{
    for(unsigned int i=0;i<p[pl].cards.size();i++)
    {
        if(p[pl].cards[i]==cc) return 1;
    }
    return 0;
}

int useCard(int pl,int cc)
{
    //Part1:Delete
    for(uint i=0;i<p[pl].cards.size();i++)
    {
        if(p[pl].cards[i]==cc) 
        {
            p[pl].cards.erase(p[pl].cards.begin()+i);
        }
    }
    //Part2:Use
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
}

void setCard(int pl)
{
    int can_have_operation=0;
    while(p[pl].cards.size()!=0&&can_have_operation<2)
    {
        for(int i=1;i<=6;i++)
        {
            if(gameOverD==1) return;
            int cc=seq[i];
            if(hasCard(pl,cc)) 
            {
                if(useCard(pl,cc)) break;
            }
        }
        can_have_operation++;
    }
    return;
}

void gamePlay()
{
    for(int pl=1;;pl++)
    {
        if(gameOverD==1) return;
        getCard(pl,2);
        setCard(pl);
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
        p[i].nextPlayer=&p[(i+playerTotal+1)%playerTotal];
        p[i].lastPlayer=&p[(i+playerTotal-1)%playerTotal];
        p[i].hp=4;
        for(int i=1;i<=4;i++)
        {
            char s[5];
            scanf("%s",s);
            p[i].cards.push_back(mpl[(int)s[0]]);
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
