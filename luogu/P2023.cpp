#include<bits/stdc++.h>
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,p,m;
ll num[N];
struct node{
    ll l,r;
    ll data;
    ll add,mul;
}tree[N<<2];
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
inline void push_down(ll i){
    ll l_len=tree[ls(i)].r-tree[ls(i)].l+1;
    ll r_len=tree[rs(i)].r-tree[rs(i)].l+1;
    if(tree[i].mul!=1){
        tree[ls(i)].data=(tree[ls(i)].data*tree[i].mul)%p;
        tree[ls(i)].mul=(tree[ls(i)].mul*tree[i].mul)%p;
        tree[ls(i)].add=(tree[ls(i)].add*tree[i].mul)%p;
        tree[rs(i)].data=(tree[rs(i)].data*tree[i].mul)%p;
        tree[rs(i)].mul=(tree[rs(i)].mul*tree[i].mul)%p;
        tree[rs(i)].add=(tree[rs(i)].add*tree[i].mul)%p;
        tree[i].mul=1;
    }
    if(tree[i].add!=0){
        tree[ls(i)].data=(tree[ls(i)].data+tree[i].add*l_len)%p;
        tree[ls(i)].add=(tree[ls(i)].add+tree[i].add)%p;
        tree[rs(i)].data=(tree[rs(i)].data+tree[i].add*r_len)%p;
        tree[rs(i)].add=(tree[rs(i)].add+tree[i].add)%p;
        tree[i].add=0;
    }
}
inline void pushup(ll i){
    tree[i].data=(tree[ls(i)].data+tree[rs(i)].data)%p;
    return;
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    tree[i].mul=1;
    if(l==r){
        tree[i].data=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(ls(i),l,mid);
    build(rs(i),mid+1,r);
    pushup(i);
}
inline void r_add(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data=(tree[i].data+val*(tree[i].r-tree[i].l+1))%p;
        tree[i].add=(tree[i].add+val)%p;
        return;
    }
    push_down(i);
    if(tree[ls(i)].r>=l)
        r_add(ls(i),l,r,val);
    if(tree[rs(i)].l<=r)
        r_add(rs(i),l,r,val);
    pushup(i);
}
inline void r_mul(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data=(tree[i].data*val)%p;
        tree[i].mul=(tree[i].mul*val)%p;
        tree[i].add=(tree[i].add*val)%p;
        return;
    }
    push_down(i);
    if(tree[ls(i)].r>=l)
        r_mul(ls(i),l,r,val);
    if(tree[rs(i)].l<=r)
        r_mul(rs(i),l,r,val);
    pushup(i);
}
inline ll r_ask(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].data;
    push_down(i);
    ll ans=0;
    if(tree[ls(i)].r>=l)
        ans=(ans+r_ask(ls(i),l,r))%p;
    if(tree[rs(i)].l<=r)
        ans=(ans+r_ask(rs(i),l,r))%p;
    return ans;
}
int main(){
    read(n),read(p);
    for(ll i=1;i<=n;i++)
        read(num[i]);
    build(1,1,n);
    read(m);
    while(m--){
        ll op,l,r,c;
        read(op);
        switch(op){
            case 1:
                read(l),read(r),read(c);
                r_mul(1,l,r,c);
                break;
            case 2:
                read(l),read(r),read(c);
                r_add(1,l,r,c);
                break;
            case 3:
                read(l),read(r);
                printf("%lld\n",r_ask(1,l,r));
        }
    }
    return 0;
}