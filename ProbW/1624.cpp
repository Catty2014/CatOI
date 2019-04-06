//D5#0001
//SDOJ #1624 ÌáÈ¡Êý×Ö
//C++

#include <bits/stdc++.h>

using namespace std;

int str2int(string s){
    int x=0,l=s.size();
    for(int i=0;i<l;i++)
        x=x*10+s[i]-'0';
    return x;
}

int main()
{
	string s,t;
	cin>>s;
	int i=0,j;
	int len=s.size();
	while(1)
	{
		while(i<len&&s[i]<'0'||s[i]>'9')
			i++;
		j=i;
		while(j<len&&s[j]>='0'&&s[j]<='9')
			j++;
		t=s.substr(i,j-i);
		int ans;
		ans=str2int(t);
		cout<<ans<<endl;
		i=j+1;
		if(i>=len) break;
	}
	return 0;
}
