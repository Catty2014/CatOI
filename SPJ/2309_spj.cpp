#include "testlib.h"
#define MAXN 55
using namespace std;

int n,m,usrc,stdc,cnt,a[MAXN],c[MAXN],x;
vector <int> v[MAXN],usre;
bool usr[MAXN];

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	m=inf.readInt();n=inf.readInt();
	for (int i=1;i<=m;i++)
	{
		a[i]=inf.readInt();
		while (!inf.eoln())
		{
			x=inf.readInt(1,n);
			v[i].push_back(x);
		}
	}
	for (int i=1;i<=n;i++) c[i]=inf.readInt();
	while (!ans.eoln()) ans.readInt();
	while (!ans.eoln()) ans.readInt();
	stdc=ans.readInt();
	char ch;
	int num=0;
	while(1)
    {
        ch=ouf.readChar();
        if(ch==32)
        {
            usre.push_back(num);
            num=0;
            continue;
        }
        if(ch==10||ch==13)
        {
            if(num!=0)
            {
                usre.push_back(num);
                num=0;
            }
            break;
        }
        num*=10;
        num+=ch-'0';
    }
    num=0;
    int fir=1;
    while(1)
    {
        ch=ouf.readChar();
        if(ch==32)
        {
            usr[num]=1;
            cnt-=c[num];
            num=0;
            continue;
        }
        if(ch==13||ch==10)
        {
            if(fir==1)
            {
                fir=0;
                continue;
            }
            if(num!=0)
            {
                usr[num]=1;
                cnt-=c[num];
                num=0;
            }
            break;
        }
        num*=10;
        num+=ch-'0';
    }
	usrc=ouf.readInt();
	//printf("%d\n",usrc);
	if (stdc!=usrc)
	{
		quitf(_wa,"Your profit differs from the standard one!QAQ");
		return 0;
	}
	for (int i=0,len=usre.size();i<len;i++)
	{
		int k=usre[i];
		for (int j=0,l=v[k].size();j<l;j++)
			if (!usr[v[k][j]])
			{
				quitf(_wa,"You didn't choose %d instrument!QAQ",v[k][j]);
				return 0;
			}
		cnt+=a[k];
	}
	if (cnt==stdc)
	{
		quitf(_ok,"Your answer is acceptable!^_^");
	}
	else
	{
		fprintf(stderr,"%d\n", cnt);
		quitf(_wa,"Wrong solution!QAQ");
	}
	return 0;
}
