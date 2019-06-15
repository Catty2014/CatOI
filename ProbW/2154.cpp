//SDOJ #2154 ╩ьндвс╢╝
//Language:C++

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct pal{
	int order;
	int length;
	string comment;
};

bool srt(const pal&a,const pal&b)
{
	if (a.length==b.length) return a.order<b.order;
	return a.length<b.length;
}

int main()
{
	int
}






