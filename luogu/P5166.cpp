#include<bits/stdc++.h>
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll n,q;
ll num[N];
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
inline void write(ll a){
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
inline void push_down(ll i){
    if(tree[i].add==1&&tree[i].l!=tree[i].r){
        tree[ls(i)].data=0;
        tree[ls(i)].add=1;
        tree[rs(i)].data=0;
        tree[rs(i)].add=1;
        tree[i].add=0;
    }
}
inline void pushup(ll i){
    tree[i].data=tree[ls(i)].data+tree[rs(i)].data;
    return;
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    if(l==r){
        tree[i].data=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(ls(i),l,mid);
    build(rs(i),mid+1,r);
    pushup(i);
}
inline void r_add(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data=0;
        tree[i].add=1;
        return;
    }
    push_down(i);
    if(tree[ls(i)].r>=l)
        r_add(ls(i),l,r);
    if(tree[rs(i)].l<=r)
        r_add(rs(i),l,r);
    pushup(i);
}
inline ll r_ask(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].data;
    push_down(i);
    ll ans=0;
    if(tree[ls(i)].r>=l)
        ans+=r_ask(ls(i),l,r);
    if(tree[rs(i)].l<=r)
        ans+=r_ask(rs(i),l,r);
    return ans;
}
int main(){
    read(n),read(q);
    for(ll i=1;i<=n;i++)
        num[i]=1;
    for(ll i=1;i<=n;i++){
        ll a,b;
        read(a);
        for(ll j=1;j<=a;j++){
            read(b);
            num[b]=0;
        }
    }
    build(1,1,n);
    while(q--){
        ll op,l,r,x;
        read(op);
        if(op==1){
            read(l),read(r);
            ll res=0;
            if(l>1)
                res+=r_ask(1,1,l-1);
            if(r<n)
                res+=r_ask(1,r+1,n);
            write(res);
            putchar('\n');
        }
        else{
            read(l),read(r),read(x);
            r_add(1,l,r);
        }
    }
    return 0;
}