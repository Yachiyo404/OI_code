#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
const int N=1e6+10;
pair<ll,ll> num[N];
deque<pair<ll,ll>> q;
inline ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
inline void write(ll a){
    if(a<0){
        pc('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    pc(a%10+'0');
}
int main(){
    ll n=read(),k=read();
    up(i,1,n){
        num[i].first=i;
        num[i].second=read();
    }
    up(i,1,n){
        while(q.size()&&q.back().second>=num[i].second)
            q.pop_back();
        q.push_back(num[i]);
        while(q.front().first<=i-k)
            q.pop_front();
        if(i>=k)
            write(q.front().second),pc(' ');
    }
    q.clear();
    pc('\n');
    up(i,1,n){
        while(q.size()&&q.back().second<=num[i].second)
            q.pop_back();
        q.push_back(num[i]);
        while(q.front().first<=i-k)
            q.pop_front();
        if(i>=k)
            write(q.front().second),pc(' ');
    }
    return 0;
}