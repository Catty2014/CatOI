#include "testlib.h"
#include <cstdio>

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc,argv);
    int a=inf.readInt();
    int b=inf.readInt();
    int c=a+b;
    int s=ouf.readInt(1,100);
    if(s!=c)
    {
        quitf(_wa,"Line1:Answer incorrect!\nExpected %d,but got %d.",c,s);
    }
    else
    {
        quitf(_ok,"Accepted!");
    }
    return 0;
}
