#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n;
ll w[40];
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
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int main(){
    read(n);
    unsigned int ans=0;
    up(i,1,n){
        ll x;
        read(x);
        up(j,0,31){
            if((x>>j)&1)
                w[j]++;
        }
    }
    up(i,0,31){
        ll andn=w[i]*w[i],orn=(n-w[i])*(n-w[i]);
        ans+=(andn*orn+(n*n-andn)*(n*n-orn))<<i;
    }
    write(ans);
    return 0;
}