#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int N=1e6+10;
ll n,ans=1;
ll jc[N],bit[N];
inline ll lowbit(ll x){
    return x&-x;
}
inline ll ask(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
inline void add(ll x,ll y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }
}
int main(){
    scanf("%lld",&n);
    jc[0]=1;
    for(ll i=1;i<=n;i++){
        jc[i]=jc[i-1]*i%mod;
        jc[i]%=mod;
    }
    for(ll i=1;i<=n;i++)
        add(i,1);
    for(ll i=1;i<=n;i++){
        ll a;
        scanf("%lld",&a);
        ans+=((ask(a)-1)*jc[n-i]%mod)%mod;
        add(a,-1);
    }
    printf("%lld",ans%mod);
    return 0;
}