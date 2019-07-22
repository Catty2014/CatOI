//USACO 1.1 TEXT Introduction
//Language:C++
//Difficulty:1
//Method:Common

/*
ID: 18111431
TASK: test
LANG: C++                 
*/

#include <cstdio>

int main()
{
	//freopen("test.in","r",stdin);  
    //freopen("test.out","w",stdout);
    /* freopen("1.in","r",stdin); */
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
	int a;
	int b;
	scanf("%d%d",&a,&b);
	int c = a + b;
	printf("%d",c);
	return 0;
}
