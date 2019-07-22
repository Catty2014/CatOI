//测验1113 题目1 #3680 苹果和虫子
//Language：C++

#include <cstdio>

int main()
{
	int n=0,x=0,y=0;
	scanf("%d %d %d",&n,&x,&y);
	int ans=0;
	int eaten=0;
	if (y%x==0) eaten=y/x;
	else eaten=y/x+1;
	ans=n-eaten;
	printf("%d",ans);
	return 0;
}
