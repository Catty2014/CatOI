#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define maxn 2000001
#define maxm 1010
using namespace std;
 
struct Trie
{
    int Next[maxn/2][26],fail[maxn/2],end[maxn/2];
    int root,L;
    int res[maxm];
    int newnode(){
        for(int i=0;i<26;i++)
            Next[L][i]=-1;
        end[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char buf[])
    {
        int len =strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(Next[now][buf[i]-'a']==-1)
                Next[now][buf[i]-'a']=newnode();
            now=Next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build(){
        queue<int>Q;
        fail[root]=root;
        for(int i=0;i<26;i++)
            if(Next[root][i]==-1)Next[root][i]=root;
        else {
            fail[Next[root][i]]=root;
            Q.push(Next[root][i]);
        }
        while(!Q.empty()){
            int now=Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
                if(Next[now][i]==-1)
                Next[now][i]=Next[fail[now]][i];
            else {
                fail[Next[now][i]]=Next[fail[now]][i];
                Q.push(Next[now][i]);
            }
        }
    }
    void query(char buf[])
    {
        int len=strlen(buf);
        int   now=root;
        /* int res=0; */
        for(int i=0;i<len;i++)
        {
            now=Next[now][buf[i]-'a'];
            int temp=now;
            while(temp!=root){

                end[temp]=0;
                temp=fail[temp];
            }
        }
        /* return res; */
    }
    void debug(){
        for(int i=0;i<L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j=0;j<26;j++)
                printf("%2d",Next[i][j]);
            printf("]\n");
        }
    }
};
char buf[maxn];
Trie ac;
int main()
{
    int t;
    int N;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        ac.init();
        for(int i=0;i<N;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        for(int i=1;i<=)
        /* printf("%d\n",ac.query(buf)); */
    }
    return 0;
}
