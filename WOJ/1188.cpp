//WOJ #1188 soundex编码 
//Diff:Lv.2
//Mtd:string
//Lang:Cpp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char t;char pf=0;char lst_pf;
    while(scanf("%c",&t)!=EOF)
    {
        pf=0;
        if(t=='B'||t=='F'||t=='P'||t=='V') pf='1';
        if(t=='C'||t=='G'||t=='J'||t=='K'||t=='Q'||t=='S'||t=='X'||t=='Z') pf='2';
        if(t=='D'||t=='T') pf='3';
        if(t=='L') pf='4';
        if(t=='M'||t=='N') pf='5';
        if(t=='R') pf='6';
        if(t==10) pf='\n';
        if(pf!=0&&pf!=lst_pf) printf("%c",pf);
        lst_pf=pf;
    }
    return 0;
}