#include <testlib.h>
typedef long double ldb;
int main(int argc, char *argv[])
{
#ifndef FILEOUT
    registerLemonChecker(argc,argv);
#else
    registerTestlibCmd(argc,argv);
#endif
    int ln=0;
    while(1)
    {
        ln++;
        ldb p=ouf.readDouble();
        ldb q=ans.readDouble();
        if(p!=q)
        {
            quitf(_wa,"Answer incorrect!\n Line%d:Expected:%.0Lf Got:%.0Lf\n",ln,p,q);
        }
        std::string r;
        std::string s;
        r=ans.readWord();
        s=ouf.readWord();
        for(int i=1;i<=12 && i<=(int)r.length();i++)
        {
            if(r[i]!=s[i]) quitf(_wa,"Answer incorrect!\n Line%d:Expected:%c Got:%c\n",ln,r[i],s[i]);
        }
        ans.readEoln();
        if(ans.eof()) break;
    }
    quitf(_ok,"Accepted!");
    return 0;
}
