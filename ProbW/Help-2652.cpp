//SDOJ #2652<Helping> 求最大值
//Language:C++

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0,x,s=0;
    scanf("%d",&x);
    for(n=1;;n++){
    	s+=(n*2)*(n*2);
    	if(s>=x) break;
    }
    printf("%d",n-1);
    return 0;
}
