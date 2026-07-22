#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll T;
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
inline void write(ll a){
    if(a<0){
        putchar('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int main(){
    read(T);
    while(T--){
        ll n,num[N];
        read(n);
        for(ll i=1;i<=2*n;i++)
            read(num[i]);
        
    }
    return 0;
}