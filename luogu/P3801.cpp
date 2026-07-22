#include<bits/stdc++.h>
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,q;
struct node{
    ll data;
    ll l,r;
    ll add;
}h[N<<2],l[N<<2];
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
inline void push_down(node *tree,ll i){
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
inline void pushup(node *tree,ll i){
    tree[i].data=(tree[ls(i)].data+tree[rs(i)].data);
    return;
}
inline void build(node *tree,ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    if(l==r){
        tree[i].data=0;
        return;
    }
    ll mid=(l+r)>>1;
    build(tree,ls(i),l,mid);
    build(tree,rs(i),mid+1,r);
    pushup(tree,i);
}
inline void r_add(node *tree,ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data=(tree[i].data+val*(tree[i].r-tree[i].l+1));
        tree[i].add=(tree[i].add+val);
        return;
    }
    push_down(tree,i);
    if(tree[ls(i)].r>=l)
        r_add(tree,ls(i),l,r,val);
    if(tree[rs(i)].l<=r)
        r_add(tree,rs(i),l,r,val);
    pushup(tree,i);
}
inline ll r_ask(node *tree,ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].data;
    push_down(tree,i);
    ll ans=0;
    if(tree[ls(i)].r>=l)
        ans=(ans+r_ask(tree,ls(i),l,r));
    if(tree[rs(i)].l<=r)
        ans=(ans+r_ask(tree,rs(i),l,r));
    return ans;
}
int main(){
    read(n),read(m),read(q);
    while(q--){
        ll op,x1,y1,x2,y2;
        read(op);
        if(op==1){
            read(x1),read(y1);
            
        }
        else{
            read(x1),read(y1),read(x2),read(y2);

        }
    }
    return 0;
}