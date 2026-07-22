#include<bits/stdc++.h>
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m;
ll num[N],d[N];
struct node{
    ll data;
    ll l,r;
    ll add;
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
    if(tree[i].add!=0){
        tree[ls(i)].data=(tree[ls(i)].data+tree[i].add*l_len);
        tree[ls(i)].add=(tree[ls(i)].add+tree[i].add);
        tree[rs(i)].data=(tree[rs(i)].data+tree[i].add*r_len);
        tree[rs(i)].add=(tree[rs(i)].add+tree[i].add);
        tree[i].add=0;
    }
}
inline void pushup(ll i){
    tree[i].data=(tree[ls(i)].data+tree[rs(i)].data);
    return;
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    if(l==r){
        tree[i].data=d[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(ls(i),l,mid);
    build(rs(i),mid+1,r);
    pushup(i);
}
inline void r_add(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data=(tree[i].data+val*(tree[i].r-tree[i].l+1));
        tree[i].add=(tree[i].add+val);
        return;
    }
    push_down(i);
    if(tree[ls(i)].r>=l)
        r_add(ls(i),l,r,val);
    if(tree[rs(i)].l<=r)
        r_add(rs(i),l,r,val);
    pushup(i);
}
inline ll r_ask(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].data;
    push_down(i);
    ll ans=0;
    if(tree[ls(i)].r>=l)
        ans=(ans+r_ask(ls(i),l,r));
    if(tree[rs(i)].l<=r)
        ans=(ans+r_ask(rs(i),l,r));
    return ans;
}
int main(){
    read(n),read(m);
    for(ll i=1;i<=n;i++)
        read(num[i]);
    for(ll i=1;i<=n;i++)
        d[i]=num[i]-num[i-1];
    build(1,1,n);
    for(ll i=1;i<=m;i++){
        ll op,l,r,k,d,p;
        read(op);
        if(op==1){
            read(l),read(r),read(k),read(d);
            r_add(1,l,l,k);
            if(l+1<=r)
                r_add(1,l+1,r,d);
            if(r<n)
                r_add(1,r+1,r+1,-(k+d*(r-l)));
        }
        else{
            read(p);
            printf("%lld\n",r_ask(1,1,p));
        }
    }
    return 0;
}