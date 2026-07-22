#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m;
ll num[N],bit[N],d[N];
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
        bit[i]+=d[i];
        ll j=i+lowbit(i);
        if(j<=x)
            bit[j]+=bit[i];
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        num[i]=i;
        d[i]=num[i]-num[i-1];
    }
    build(n);
    while(m--){
        ll op,x,y;
        scanf("%lld",&op);
        if(op==1){
            ll k;
            scanf("%lld%lld%lld",&x,&y,&k);
            add(x,k);
            add(y+1,-1*k);
        }
        else{
            scanf("%lld",&x);
            printf("%lld\n",ask(x));
        }
    }
    return 0;
}