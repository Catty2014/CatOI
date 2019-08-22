#include<iostream>
#include<cstring>
using namespace std;
#define B 10000
#define ll long long
struct BIG{//无符号
    int len,a[10001];
    BIG(){
        len=1;memset(a,0,sizeof(0));
    }
    BIG(int n){
        *this=n;
    }
    BIG operator=(int n){
        len=0;
        if(!n)len=1;
        while(n)
            a[++len]=n%B,n/=B;
    }
    BIG operator=(string s){
        len=1;int l=s.size(),k=1;
        for(int i=l-1;i>=0;i--){
            if(k>=B){
                k=1;len++;
            }
            a[len]=(s[i]-'0')*k+a[len];
            k*=10;
        }
    }
    BIG operator =(const BIG & t){
        len=t.len;memcpy(a,t.a,sizeof(t.a));
    }
    bool operator <(const BIG&t)const{
        if(len!=t.len)return len<t.len;
        for(int i=len;i>=1;i--)
            if(a[i]!=t.a[i])
                return a[i]<t.a[i];
    }
    bool operator >(const BIG&t)const{
        return t < *this;
    }
    bool operator ==(const BIG&t)const{
        return !(*this<t&&*this>t);
    }
    bool operator <=(const BIG&t)const{
        return !(*this>t);
    }
    bool operator >=(const BIG&t)const{
        return !(*this<t);
    }
    bool operator !=(const BIG&t)const{
        return !(*this==t);
    }
    BIG operator+(  BIG& t) const{  
        BIG ret;
        ret.len=max(len,t.len);
        for(int i=1;i<=ret.len;i++){
            ret.a[i]+=a[i]+t.a[i];
            ret.a[i+1]+=ret.a[i]/B;
            ret.a[i]%=B;
        }
        if(ret.a[ret.len+1]>0)ret.len++;
        return ret;
    }
    BIG operator-(BIG&t) const{//一定大减小
        BIG ret=*this;
        for(int i=1;i<=ret.len;i++){
            if(ret.a[i]<t.a[i]){
                ret.a[i]+=B;
                ret.a[i+1]-=1;
            }
            ret.a[i]=ret.a[i]-t.a[i];
        }
        while(ret.len>1&&ret.a[ret.len]==0)ret.len--;
        return ret;
    }
    BIG operator*(BIG&t) const{
        BIG ret;
        ret.len=len+t.len-1;
        for(int i=1;i<=len;i++)//竖式运算
            for(int j=1;j<=t.len;j++)
                ret.a[i+j-1]+=a[i]*t.a[j];
        for(int i=1;i<=ret.len;i++)//处理进位
            if(ret.a[i]>B){
                ret.a[i+1]+=ret.a[i]/B;
                ret.a[i]%=B;
            } 
        int &l=ret.len;
        while(ret.a[l+1])l++,ret.a[l+1]+=ret.a[l]/B,ret.a[l]%=B;//处理高位进位 
        return ret;
    } 

    BIG operator/(long long  t)const {
        BIG ret;
        int x=0;
        if(len==1&&a[1]==0)return 0;
        for(int i=len;i>=1;i--){
            ret.a[i]=((ll)x*B+a[i])/t;
            x=((ll)x*B+a[i])%t;
        }
        ret.len=len;
        while(ret.a[ret.len]==0&&ret.len>1)ret.len--;
        return ret;
    }
};
ostream & operator << (ostream &ou,const BIG& t){
    ou<<t.a[t.len];
    for(int i=t.len-1;i>=1;i--){
        int k=B/10,x=t.a[i];
        while(k){
            ou<<x/k;
            x%=k;
            k/=10;
        }       
    }       
    return ou;
}
istream&operator>>(istream&in,BIG & t){
    string s;in>>s;t=s;return in;
}
int main(){
    BIG a;BIG b;
    cin>>a;cin>>b;
    cout<<a+b;
    return 0;
}
