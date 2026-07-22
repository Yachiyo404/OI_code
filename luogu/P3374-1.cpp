#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m;
ll num[N],bit[N];
inline ll lowbit(ll x){
    return x&(-1*x);
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
inline void build(ll x){
    for(ll i=1;i<=x;i++){
        bit[i]+=num[i];
        ll j=i+lowbit(i);
        if(j<=x)
            bit[j]+=bit[i];
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    build(n);
    while(m--){
        ll op,x,y;
        scanf("%lld%lld%lld",&op,&x,&y);
        if(op==1)
            add(x,y);
        else
            printf("%lld\n",ask(y)-ask(x-1));
    }
    return 0;
}