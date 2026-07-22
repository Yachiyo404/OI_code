#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#ifdef __unix__
#define getchar getchar_unlocked
#else
#define getchar _getchar_nolock
#endif
using namespace std;
typedef long long ll;
inline ll read(){
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
    return x*f;
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
const int N=2e5+10;
ll n,m,block;
ll k[N],bl[N],l[N>>1],f[N],to[N];
inline void replace(ll p,ll w){
    k[p]=w;
    down(i,l[bl[p]+1]-1,l[bl[p]]){
        if(i+k[i]>=l[bl[i]+1]){
            f[i]=1;
            to[i]=i+k[i];
        }
        else{
            f[i]=f[i+k[i]]+1;
            to[i]=to[i+k[i]];
        }
    }
}
inline ll ask(ll p){
    ll ret=0;
    while(p<=n){
        ret+=f[p];
        p=to[p];
    }
    return ret;
}
int main(){
    n=read();
    block=sqrt(n);
    up(i,1,n){
        k[i]=read();
        bl[i]=(i-1)/block+1;
        if(bl[i]!=bl[i-1])
            l[bl[i]]=i;
    }
    l[bl[n]+1]=n+1;
    down(i,n,1){
        if(i+k[i]>=l[bl[i]+1]){
            f[i]=1;
            to[i]=i+k[i];
        }
        else{
            f[i]=f[i+k[i]]+1;
            to[i]=to[i+k[i]];
        }
    }
    m=read();
    ll op,p,w;
    while(m--){
        op=read(),p=read();
        if(op==1)
            printf("%lld\n",ask(p+1));
        else{
            w=read();
            replace(p+1,w);
        }
    }
    return 0;
}