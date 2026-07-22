#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5e5+10;
const ll MOD=9223372036854775806;
ll arr[N];
struct node{
    ll l,r;
    ll sum;
    ll add;
    ll mul;
}tree[4*N];
inline void push_down(ll i){
    ll lc=i*2,rc=i*2+1;
    ll len_l=tree[lc].r-tree[lc].l+1;
    ll len_r=tree[rc].r-tree[rc].l+1;
    if(tree[i].mul!=1){
        tree[lc].sum=(tree[lc].sum*tree[i].mul)%MOD;
        tree[lc].mul=(tree[lc].mul*tree[i].mul)%MOD;
        tree[lc].add=(tree[lc].add*tree[i].mul)%MOD;
        tree[rc].sum=(tree[rc].sum*tree[i].mul)%MOD;
        tree[rc].mul=(tree[rc].mul*tree[i].mul)%MOD;
        tree[rc].add=(tree[rc].add*tree[i].mul)%MOD;
        tree[i].mul=1;
    }
    if(tree[i].add!=0){
        tree[lc].sum=(tree[lc].sum+tree[i].add*len_l)%MOD;
        tree[lc].add=(tree[lc].add+tree[i].add)%MOD;
        tree[rc].sum=(tree[rc].sum+tree[i].add*len_r)%MOD;
        tree[rc].add=(tree[rc].add+tree[i].add)%MOD;
        tree[i].add=0;
    }
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    tree[i].mul=1;
    if(l==r){
        tree[i].sum=arr[l]%MOD;
        return;
    }
    ll mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%MOD;
}
inline void r_add(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].sum=(tree[i].sum+val*(tree[i].r-tree[i].l+1))%MOD;
        tree[i].add=(tree[i].add+val)%MOD;
        return;
    }
    push_down(i);
    if(tree[i*2].r>=l)
        r_add(i*2,l,r,val);
    if(tree[i*2+1].l<=r)
        r_add(i*2+1,l,r,val);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%MOD;
}
inline void r_mul(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].sum=(tree[i].sum*val)%MOD;
        tree[i].mul=(tree[i].mul*val)%MOD;
        tree[i].add=(tree[i].add*val)%MOD;
        return;
    }
    push_down(i);
    if(tree[i*2].r>=l)
        r_mul(i*2,l,r,val);
    if(tree[i*2+1].l<=r)
        r_mul(i*2+1,l,r,val);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%MOD;
}
inline ll r_ask(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    push_down(i);
    ll res=0;
    if(tree[i*2].r>=l)
        res=(res+r_ask(i*2,l,r))%MOD;
    if(tree[i*2+1].l<=r)
        res=(res+r_ask(i*2+1,l,r))%MOD;
    return res;
}
int main(){
    ll n,m;
    scanf("%d%d",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    build(1,1,n);
    while(m--){
        ll op;
        scanf("%d",&op);
        if(op==1){
            ll l,r;
            ll val;
            scanf("%d%d%lld",&l,&r,&val);
            r_add(1,l,r,val);
        }
        else if(op==2){
            ll l,r;
            ll val;
            scanf("%d%d%lld",&l,&r,&val);
            r_mul(1,l,r,val);
        }
        else if(op==3){
            ll pos;
            ll val;
            scanf("%d%lld",&pos,&val);
            r_add(1,pos,pos,val);
        }
        else if(op==4){
            ll pos;
            ll val;
            scanf("%d%lld",&pos,&val);
            r_mul(1,pos,pos,val);
        }
        else if(op==5){
            ll l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",r_ask(1,l,r));
        }
        else if(op==6){
            ll pos;
            scanf("%d",&pos);
            printf("%lld\n",r_ask(1,pos,pos));
        }
    }
    return 0;
}