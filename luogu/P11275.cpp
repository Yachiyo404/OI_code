#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
#define int128 __int128_t
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
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
inline ll gcd(ll x,ll y){
    if(x%y==0) 
        return y;
    return gcd(y,x%y);
}
inline ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main(){
    ll q=read();
    while(q--){
        ll u=read(),v=read();
        ll g=gcd(u,v);
        if(u==v)
            write(0);
        else if(g==u)
            write(v);
        else if(g==v)
            write(u);
        else
            write(u+v);
        pc('\n');
    }
    return 0;
}