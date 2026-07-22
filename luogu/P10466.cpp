#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n;
ll num[N];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
int main(){
    read(n);
    up(i,1,n)
        read(num[i]);
    set<pair<ll,ll>> s;
    s.insert({num[1],1});
    up(i,2,n){
        ll p=LONG_LONG_MAX,j=-1;
        s.insert({num[i],i});
        auto it=s.find({num[i],i});
        if(it!=s.begin()){
            auto a=prev(it);
            p=abs((*a).first-num[i]);
            j=(*a).second;
        }
        auto b=next(it);
        if(b!=s.end()){
            if(abs((*b).first-num[i])<p){
                p=abs((*b).first-num[i]);
                j=(*b).second;
            }
        }
        printf("%lld %lld\n",p,j);
    }
    return 0;
}