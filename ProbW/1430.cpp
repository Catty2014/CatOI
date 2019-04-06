//SDOJ #1430 河中跳房子
//Language:C++

#include <bits/stdc++.h>

using namespace std;

int a[233333]={0};

int  L,N,M;
int check(int mid) 
{ 
  int m=0,t=a[0]; 
  for(int i=1;i<=N;i++) 
  { 
    int x=a[i]-t; 
    if(x<mid)  
      m++;
    else 
      t=a[i]; 
  } 
  if(m<=M) return 1; 
    else return 0; 
 
}

int main(){ 
  cin>>L>>N>>M; 
  for(int i=1;i<=N;i++){ 
    cin>>a[i]; 
  }   
  a[0]=0;a[N+1]=L;N++; 
  int l=0,r=L,mid; 
  while(l+1<r){ 
    mid=(l+r)/2; 
    if(check(mid))  
      l=mid;  
    else 
      r=mid;     
  } 
  if(check(r))cout<<r; 
  else cout<<l;  
  return 0; 
}
