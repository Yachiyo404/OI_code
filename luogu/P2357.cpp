#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m;
ll num[N],D[N];
ll tree1[N],tree2[N];
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
inline void range_add(ll l,ll r,ll k){
    add(tree1,l,k);
    add(tree1,r+1,-k);
    add(tree2,l,l*k);
    add(tree2,r+1,-(r+1)*k);
}
inline ll range_query(ll l,ll r){
    ll sum_r=(r+1)*ask(tree1,r)-ask(tree2,r);
    ll sum_l=l*ask(tree1,l-1)-ask(tree2,l-1);
    return sum_r-sum_l;
}
inline ll point_query(ll x){
    return ask(tree1,x);
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&num[i]);
        D[i]=num[i]-num[i-1];
        add(tree1,i,D[i]);
        add(tree2,i,i*D[i]);
    }
    while(m--){
        ll op,x,y,k;
        scanf("%lld",&op);
        switch(op){
            case 1:
                scanf("%lld%lld%lld",&x,&y,&k);
                range_add(x,y,k);
                break;
            case 2:
                scanf("%lld",&k);
                range_add(1,1,k);
                break;
            case 3:
                scanf("%lld",&k);
                range_add(1,1,-k);
                break;
            case 4:
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",range_query(x,y));
                break;
            case 5:
                printf("%lld\n",point_query(1));
                break;
        }
    }
    return 0;
}