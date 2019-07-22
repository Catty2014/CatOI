#include <cstdio>
#include <cstring>

#define C ('a'-1)

char vin(char a,char b)
{
    char c=b-a+1;
    
    c=(c+26)%26;
    if(c==0) c=26;
    c+=C;
    return c;
}

char a[133],b[1333];
int la,lb;
bool bb[1333];

int main()
{
#ifdef FILEOUT
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
#endif
    scanf("%s",a+1);
    scanf("%s",b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    for(int i=1;i<=lb;i++)
    {
        if(b[i]>=65&&b[i]<=90)  
        {
            b[i]+=32;
            bb[i]=1;
        }
    }
    for(int i=1;i<=la;i++)
    {
        if(a[i]>=65&&a[i]<=90)
        {
            a[i]+=32;
        }
    }
    for(int i=1;i<=lb;i++)
    {
        int pa=i,pb=i;
        while(pa>la) pa-=la;
        if(pa==0) pa+=la;
        printf("%c",vin(a[pa],b[pb])-bb[pb]*32);
    }
}
