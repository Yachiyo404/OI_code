#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
using namespace std;
typedef long long ll;
ll x,y; 
inline void exgcd(ll a,ll b){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
}
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
    ll a,b;
    read(a),read(b);
    exgcd(a,b);
    x=(x%b+b)%b;
    cout<<x;
    return 0;
}