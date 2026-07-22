#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m;
ll d[N],bit1[N],bit2[N];
inline ll lowbit(ll x){
    return x&-x;
}
inline void add(ll *tree,ll x,ll y){
    while(x<=n){
        tree[x]+=y;
        x+=lowbit(x);
    }
}
inline ll ask(ll *tree,ll x){
    ll sum=0;
    while(x){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
inline void r_add(ll l,ll r,ll x){
    add(bit1,l,x);
    add(bit1,r+1,-x);
    add(bit2,l,l*x);
    add(bit2,r+1,-(r+1)*x);
}
inline ll r_ask(ll l,ll r){
    ll suml=l*ask(bit1,l-1)-ask(bit2,l-1);
    ll sumr=(r+1)*ask(bit1,r)-ask(bit2,r);
    return sumr-suml;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        add(bit1,i,d[i]);
        add(bit2,i,i*d[i]);
    }
    while(m--){
        char op;
        ll k,x,l,r;
        scanf("%c",&op);
        if(op=='x'){
            scanf("%lld%lld",&x,&k);
            r_add(x,x,k);
        }
        else{
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",r_ask(l,r));
        }
    }
    return 0;
}