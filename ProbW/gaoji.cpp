#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
using namespace std;
int s=1000,khf;


/*=============== all the structures ===============*/


typedef struct Frame
{
COORD position[2];
int flag;
}Frame;




/*=============== all the functions ===============*/


void SetPos(COORD a)// set cursor 
{
HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(out, a);
}


void SetPos(int i, int j)// set cursor
{
COORD pos={i, j};
SetPos(pos);
}


void HideCursor()
{
CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


//把第y行，[x1, x2) 之间的坐标填充为 ch
void drawRow(int y, int x1, int x2, char ch)
{
SetPos(x1,y);
for(int i = 0; i <= (x2-x1); i++)
cout<<ch;
}


//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawRow(COORD a, COORD b, char ch)
{
if(a.Y == b.Y)
drawRow(a.Y, a.X, b.X, ch);
else
{
SetPos(0, 25);
cout<<"error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";
system("pause");
}
}


//把第x列，[y1, y2] 之间的坐标填充为 ch
void drawCol(int x, int y1, int y2, char ch)
{
int y=y1;
while(y!=y2+1)
{
SetPos(x, y);
cout<<ch;
y++;
}
}


//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawCol(COORD a, COORD b, char ch)
{
if(a.X == b.X)
drawCol(a.X, a.Y, b.Y, ch);
else
{
SetPos(0, 25);
cout<<"error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";
system("pause");
}
}


//左上角坐标、右下角坐标、用row填充行、用col填充列
void drawFrame(COORD a, COORD b, char row, char col)
{
drawRow(a.Y, a.X+1, b.X-1, row);
drawRow(b.Y, a.X+1, b.X-1, row);
drawCol(a.X, a.Y+1, b.Y-1, col);
drawCol(b.X, a.Y+1, b.Y-1, col);
}


void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
COORD a={x1, y1};
COORD b={x2, y2};
drawFrame(a, b, row, col);
}


void drawFrame(Frame frame, char row, char col)
{
COORD a = frame.position[0];
COORD b = frame.position[1];
drawFrame(a, b, row, col);
}


void drawPlaying()
{
drawFrame(0, 0, 48, 24, '=', '|');//draw map frame;
drawFrame(49, 0, 79, 4, '-', '|');//draw output frame
drawFrame(49, 4, 79, 9, '-', '|');//draw score frame
drawFrame(49, 9, 79, 20, '-', '|');//draw operate frame
drawFrame(49, 20, 79, 24, '-', '|');//draw other message frame
SetPos(52, 6);
cout<<"得分：";
SetPos(52, 7);
cout<<"称号：";
SetPos(52,10);
cout<<"操作方式：";
SetPos(52,12);
cout<<" a,s,d,w 控制战机移动。";
SetPos(52,14);
cout<<" p 暂停游戏。";
SetPos(52,16);
cout<<" e 退出游戏。";
SetPos(52,18);
cout<<"按j,k,l键发射子弹！"; 
}


//在[a, b)之间产生一个随机整数
int random(int a, int b)
{
int c=(rand() % (a-b))+ a;
return c;
}


//在两个坐标包括的矩形框内随机产生一个坐标
COORD random(COORD a, COORD b)
{
int x=random(a.X, b.X);
int y=random(a.Y, b.Y);
COORD c={x, y};
return c;
}


bool judgeCoordInFrame(Frame frame, COORD spot)
{
if(spot.X>=frame.position[0].X)
if(spot.X<=frame.position[1].X)
if(spot.Y>=frame.position[0].Y)
if(spot.Y<=frame.position[0].Y)
return true;
return false;
}


void printCoord(COORD a)
{
cout<<"( "<<a.X<<" , "<<a.Y<<" )";
}


void printFrameCoord(Frame a)
{
printCoord(a.position[0]);
cout<<" - ";
printCoord(a.position[1]);
}


int drawMenu()
{
SetPos(29, 0);
cout<<"gao ji"<<endl;
SetPos(30, 1);
cout<<"搞 机"<<endl;
cout<<" "<<""; 
SetPos(12, 7);
int ccc=random(1,6);
if(ccc==1)cout<<"分数越高，敌人的移动速度越快，但听说也有让敌人速度变慢的方式"<<endl;
if(ccc==2)cout<<"传闻达到一定分数，会进入丧心病狂的异次元"<<endl;
if(ccc==3)cout<<"敌人的闪避率和护甲会随你的分数增加而增加！"<<endl;
if(ccc==4)cout<<"你的子弹会因头领的怨念而变慢，要小心！"<<endl;
if(ccc==5)cout<<"连续开枪时炮管可能过热，会短暂的无法射击！"<<endl;
drawRow(3, 0, 79, '-');
drawRow(5, 0, 79, '-');
SetPos(28, 4);
cout<<"w 和 s 选择， k 确定";
SetPos(15, 11);
cout<<"1. 傻逼的敌人";
SetPos(15, 13);
cout<<"2. 简单的敌人";
drawRow(20, 0, 79, '-');
drawRow(22, 0, 79, '-');
SetPos(47, 11);
cout<<"傻逼的敌人：";
SetPos(51, 13);
cout<<"傻逼的敌人移动速度特别慢。";
int j=11;
SetPos(12, j);
cout<<">>";


//drawFrame(45, 9, 79, 17, *=*, *|*);


while(1)
{if( _kbhit() )
{
char x=_getch();
switch (x)
{
case 'w' :
{
if( j == 13)
{
SetPos(12, j);
cout<<"　";
j = 11;
SetPos(12, j);
cout<<">>";
SetPos(51, 13);
cout<<"　　　　　　　　　　　　";
SetPos(47, 11);
cout<<"傻逼的敌人：";
SetPos(51, 13);
cout<<"傻逼的敌人移动速度特别慢。";
}
break;
}
case 's' :
{
if( j == 11 )
{
SetPos(12, j);
cout<<"　";
j = 13;
SetPos(12, j);
cout<<">>";
SetPos(51, 13);
cout<<"　　　　　　　　　　　　　　";
SetPos(47, 11);
cout<<"简单的敌人：";
SetPos(51, 13);
cout<<"简单的敌人移动速度较慢。";
}
break;
}
case 'k' :
{
if (j == 8)return 1;
else return 2;
}
}
}
}
}


/* 
DWORD WINAPI MusicFun(LPVOID lpParamte)
{
//DWORD OBJ;
sndPlaySound(TEXT("bgm.wav"), SND_FILENAME|SND_ASYNC);
return 0;
}
*/




/*================== the Game Class ==================*/


class Game
{
public:
COORD position[10];
COORD bullet[10];
Frame enemy[8];
int score;
int rank;
int rankf;
string title;
int flag_rank;


Game ();

//初始化所有
void initPlane();
void initBullet();
void initEnemy();


//初始化其中一个
//void initThisBullet( COORD );
//void initThisEnemy( Frame );


void planeMove(char);
void bulletMove();
void enemyMove();

//填充所有
void drawPlane();
void drawPlaneToNull();
void drawBullet();
void drawBulletToNull();
void drawEnemy();
void drawEnemyToNull();


//填充其中一个
void drawThisBulletToNull( COORD );
void drawThisEnemyToNull( Frame );


void Pause();
void Playing();
void judgePlane();
void judgeEnemy();


void Shoot();


void GameOver();
void printScore();
};


Game::Game()
{
initPlane();
initBullet();
initEnemy();
score = 0;
rank = 25;
rankf = 0;
flag_rank = 0;
}


void Game::initPlane()
{
COORD centren={39, 22};
position[0].X=position[5].X=position[7].X=position[9].X=centren.X;
position[1].X=centren.X-2;
position[2].X=position[6].X=centren.X-1;
position[3].X=position[8].X=centren.X+1;
position[4].X=centren.X+2;
for(int i=0; i<=4; i++)
position[i].Y=centren.Y;
for(int i=6; i<=8; i++)
position[i].Y=centren.Y+1;
position[5].Y=centren.Y-1;
position[9].Y=centren.Y-2;
}//未完待续



//打飞机游戏
void Game::drawPlane()
{
for(int i=0; i<9; i++)
{
SetPos(position[i]);
if(i!=5)
cout<<"*";
else if(i==5)
cout<<"|";
}
}


void Game::drawPlaneToNull()
{
for(int i=0; i<9; i++)
{
SetPos(position[i]);
cout<<" ";
}
}


void Game::initBullet()
{
for(int i=0; i<10; i++)
bullet[i].Y = 30;
}


void Game::drawBullet()
{
if(score>=30&&score<=70)
{ 
SetPos(30,2);
cout<<"摧毁敌机可升级你的子弹！"; 
}
if(score==75)
{ 
SetPos(30,2);
cout<<"                            "; 
}
if(score>=120&&score<=150)
{ 
SetPos(30,2);
cout<<"子弹升级为风翼弹！           "; 
}
if(score==155)
{ 
SetPos(30,2);
cout<<"                        "; 
}
if(score>=300&&score<=360)
{ 
SetPos(30,2);
cout<<"子弹升级为二连枪！          "; 
}
if(score==365)
{ 
SetPos(30,2);
cout<<"                        "; 
}
if(score>=480&&score<=530)
{ 
SetPos(30,2);
cout<<"子弹升级为双管炮！       "; 
}
if(score==535)
{ 
SetPos(30,2);
cout<<"                        "; 
}
if(score>=700&&score<=750)
{ 
SetPos(30,2);
cout<<"子弹升级为上供霞弹！      "; 
}
if(score==755)
{ 
SetPos(30,2);
cout<<"                        "; 
}
if(score>=1000&&score<=1025)
{ 
SetPos(30,2);
cout<<"子弹升级为加特林！         "; 
}
if(score>=1030&&score<=1345)
{ 
SetPos(30,2);
cout<<"天神祝福效果（子弹时间）     "; 
}
if(score>=1350&&score<=1395)
{ 
SetPos(30,2);
cout<<"即将进入高难本！                 "; 
}
if(score==1400)
{ 
SetPos(30,2);
cout<<"进入异次元！                   "; 
}
for(int i=0; i<10; i++)
{
if(( bullet[i].Y != 30))
{
SetPos(bullet[i]);
if(khf==4) 
cout<<"。"<<endl; 
if(khf==3)
cout<<"^"<<endl;
if(khf==2)
cout<<"|"<<endl;
if(khf==1)
cout<<"‖"<<endl;
if(khf==0)
cout<<"∴" <<endl;
if(khf==-1)
cout<<"┋" <<endl;

}
}
}


void Game::drawBulletToNull()
{
for(int i=0; i<10; i++)
if( bullet[i].Y != 30 )
{
COORD pos={bullet[i].X, bullet[i].Y+1};
SetPos(pos);
cout<<" ";
}
}


void Game::initEnemy()
{
COORD a={1, 1};
COORD b={45, 15};
for(int i=0; i<8; i++)
{
enemy[i].position[0] = random(a, b);
enemy[i].position[1].X = enemy[i].position[0].X + 3;
enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
}
}


void Game::drawEnemy()
{
for(int i=0; i<8; i++)
drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');
}


void Game::drawEnemyToNull()
{
for(int i=0; i<8; i++)
{
drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');
}
}


void Game::Pause()
{
SetPos(61,2);
cout<<" ";
SetPos(61,2);
cout<<"暂停中...";
char c=_getch();
while(c!='p')
c=_getch();
SetPos(61,2);
cout<<" ";
}


void Game::planeMove(char x)
{
if(x == 'a')
if(position[1].X != 1)
for(int i=0; i<=9; i++)
position[i].X -= 2;

if(x == 's')
if(position[7].Y != 23)
for(int i=0; i<=9; i++)
position[i].Y += 1;


if(x == 'd')
if(position[4].X != 47)
for(int i=0; i<=9; i++)
position[i].X += 2;


if(x == 'w')
if(position[5].Y != 3)
for(int i=0; i<=9; i++)
position[i].Y -= 1;
}


void Game::bulletMove()
{
for(int i=0; i<10; i++)
{
if( bullet[i].Y != 30)
{
bullet[i].Y -= 1;
if( bullet[i].Y == 1 )
{
COORD pos={bullet[i].X, bullet[i].Y+1};
drawThisBulletToNull( pos );
bullet[i].Y=30;
}

}
}
}


void Game::enemyMove()
{
for(int i=0; i<8; i++)
{
for(int j=0; j<2; j++)
enemy[i].position[j].Y++;


if(24 == enemy[i].position[1].Y)
{
COORD a={1, 1};
COORD b={45, 3};
enemy[i].position[0] = random(a, b);
enemy[i].position[1].X = enemy[i].position[0].X + 3;
enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
}
}
}


void Game::judgePlane()
{
for(int i = 0; i < 8; i++)
for(int j=0; j<9; j++)
if(judgeCoordInFrame(enemy[i], position[j]))
{
SetPos(62, 1);
cout<<"你嗝屁了！";
drawFrame(enemy[i], '+', '+');
Sleep(1000);
GameOver();
break;
}
}


void Game::drawThisBulletToNull( COORD c)
{
SetPos(c);
cout<<" ";
}


void Game::drawThisEnemyToNull( Frame f )
{
drawFrame(f, ' ', ' ');
}


void Game::judgeEnemy()
{
for(int i = 0; i < 8; i++)
for(int j = 0; j < 10; j++)
if( judgeCoordInFrame(enemy[i], bullet[j]) )
{
score += 5;
drawThisEnemyToNull( enemy[i] );
COORD a={1, 1};
COORD b={45, 3};
enemy[i].position[0] = random(a, b);
enemy[i].position[1].X = enemy[i].position[0].X + 3;
enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
drawThisBulletToNull( bullet[j] );
bullet[j].Y = 30;
}
}


void Game::Shoot()
{
for(int i=0; i<10; i++)
if(bullet[i].Y == 30)
{
bullet[i].X = position[5].X;
bullet[i].Y = position[5].Y-1;
break;
}
}


void Game::printScore()
{
if(score == 120 && flag_rank == 0)
{
rank -= 3;
flag_rank = 1;
}


else if( score == 300 && flag_rank == 1)
{
rank -= 5;
flag_rank = 2;
}
else if( score == 480 && flag_rank == 2)
{
rank -= 5;
flag_rank = 3;
}
else if( score == 700 && flag_rank == 3)
{
rank -= 3;
flag_rank = 4;
}
else if( score == 1000 && flag_rank == 4)
{
rank += 2;
khf=-1;
}
else if( score == 1200 && flag_rank == 4)
{
rank-=2;
khf=-1;
}
else if( score == 1400 && flag_rank == 4)
{
rank-=5;
khf=-1;
}
int x=rank/5;
SetPos(60, 6);
cout<<score;


if( rank!=rankf )
{
SetPos(60, 7);
if( x == 5){
title="初级飞行员";
}
else if( x == 4){
title="垃圾飞行员";
khf=4;
}
else if( x == 3){
title="渣渣飞行员";
khf=3;
}
else if( x == 2 ){
	title="老斯基    ";
	khf=2;
}
else if(x==1){
	title="卍飞行员  ";
	khf=1; 
}

else if(x==0){
	title="挂狗飞行员";
	khf=0; 
}
else if(khf==-1){
	title="天神飞行员"; 
}

cout<<title;
}
rankf = rank;
}


void Game::Playing()
{
//HANDLE MFUN;
//MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL); 


drawEnemy();
drawPlane();


int flag_bullet = 0;
int flag_enemy = 0;


while(1)
{
Sleep(8);
if(_kbhit())
{
char x = _getch();
if ('a' == x || 's' == x || 'd' == x || 'w' == x)
{
drawPlaneToNull();
planeMove(x);
drawPlane();
judgePlane();
}
else if ('p' == x)
Pause();
else if( 'k' == x||'j'==x||'l'==x)
Shoot();
else if( 'e' == x)
{
//CloseHandle(MFUN);
GameOver();
break;
}

}
/* 处理子弹 */
if( 0 == flag_bullet )
{
bulletMove();
drawBulletToNull();
drawBullet();
judgeEnemy();
}
flag_bullet++;
if( 5 == flag_bullet )
flag_bullet = 0;


/* 处理敌人 */
if( 0 == flag_enemy )
{
drawEnemyToNull();
enemyMove();
drawEnemy();
judgePlane();
}
flag_enemy++;
if( flag_enemy >= rank )
flag_enemy = 0;


/* 输出得分 */
printScore();
}
}


void Game::GameOver()
{
system("cls");
COORD p1={28,9};
COORD p2={53,15};
drawFrame(p1, p2, '=', '|');
SetPos(30,12);
string str="你嗝屁了!";
for(int i=0; i<str.size(); i++)
{
Sleep(80);
cout<<str[i];
}
Sleep(1000);
system("cls");
drawFrame(p1, p2, '=', '|');
SetPos(31, 11);
cout<<"击落敌机："<<score/5<<" 架";
SetPos(31, 12);
cout<<"得　　分："<<score;
SetPos(31, 13);
cout<<"颁发称号："<<title;
SetPos(30, 16);
Sleep(1000);
cout<<"中毒了没？ 是（y）| 否（n）";
as:
char x=_getch();
if (x == 'n')
exit(0);
else if (x == 'y')
{
system("cls");
s=1000;
Game game;
int a = drawMenu();
if(a == 2)
game.rank = 20;
system("cls");
drawPlaying();
game.Playing();
}
else goto as;
}


/*================== the main function ==================*/
int main()
{
//游戏准备
srand((int)time(0));//随机种子
HideCursor();//隐藏光标

Game game;
int a = drawMenu();
if(a == 2)
game.rank = 20;
system("cls");
drawPlaying();
game.Playing();
}
