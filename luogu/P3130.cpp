#include<bits/stdc++.h>
#define ll long long
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e5+10;
ll n,m;
ll num[N];
struct node{
    ll l,r;
    ll sum;
    ll add;
    ll min;
}tree[N*4];
inline ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
inline void pushup(ll x){
    tree[x].sum=tree[ls(x)].sum+tree[rs(x)].sum;
    tree[x].min=min(tree[ls(x)].min,tree[rs(x)].min);
    return;
}
inline void pushdown(ll i){
    ll lenl=tree[ls(i)].r-tree[ls(i)].l+1;
    ll lenr=tree[rs(i)].r-tree[rs(i)].l+1;
    if(tree[i].add!=0){
        tree[ls(i)].sum+=tree[i].add*lenl;
        tree[ls(i)].add+=tree[i].add;
        tree[ls(i)].min+=tree[i].add;
        tree[rs(i)].sum+=tree[i].add*lenr;
        tree[rs(i)].add+=tree[i].add;
        tree[rs(i)].min+=tree[i].add;
        tree[i].add=0;
    }
    return;
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].add=0;
    if(tree[i].l==tree[i].r){
        tree[i].sum=tree[i].min=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(ls(i),l,mid);
    build(rs(i),mid+1,r);
    pushup(i);
}
inline void r_add(ll i,ll l,ll r,ll k){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].add+=k;
        tree[i].min+=k;
        return;
    }
    pushdown(i);
    if(tree[ls(i)].r>=l)
        r_add(ls(i),l,r,k);
    if(tree[rs(i)].l<=r)
        r_add(rs(i),l,r,k);
    pushup(i);
}
inline ll r_askn(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    ll ans=0;
    pushdown(i);
    if(tree[ls(i)].r>=l)
        ans+=r_askn(ls(i),l,r);
    if(tree[rs(i)].l<=r)
        ans+=r_askn(rs(i),l,r);
    return ans;
}
inline ll r_askm(ll i,ll l,ll r){
    if(l<=tree[i].l&&tree[i].r<=r)
        return tree[i].min;
    ll ans=0x7fffffff;
    pushdown(i);
    if(tree[ls(i)].r>=l)
        ans=r_askm(ls(i),l,r);
    if(tree[rs(i)].l<=r)
        ans=min(ans,r_askm(rs(i),l,r));
    return ans;
}
int main(){
    n=read(),m=read();
    for(ll i=1;i<=n;i++)
        num[i]=read();
    build(1,1,n);
    while(m--){
        char ch;
        ll l,r;
        cin>>ch;
        if(ch=='M'){
            l=read(),r=read();
            printf("%lld\n",r_askm(1,l,r));
        }
        else if(ch=='P'){
            ll a;
            l=read(),r=read(),a=read();
            r_add(1,l,r,a);
        }
        else{
            l=read(),r=read();
            printf("%lld\n",r_askn(1,l,r));
        }
    }
    return 0;
}