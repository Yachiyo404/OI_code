#include<bits/stdc++.h>
#define ls(i) ((i)<<1)
#define rs(i) ((i)<<1|1)
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll m,mod,t,len,lstans;
ll a[N];
struct node{
    ll l,r;
    ll data,add,mx;
}tree[N<<2];
void pushup(ll i){
    tree[i].data=tree[ls(i)].data+tree[rs(i)].data;
    tree[i].mx=max(tree[ls(i)].mx,tree[rs(i)].mx);
}
void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    if(l==r){
        tree[i].data=a[l];
        tree[i].mx=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(ls(i),l,mid);
    build(rs(i),mid+1,r);
    pushup(i);
    return;
}
void pushdown(ll i){
    ll len_l=tree[ls(i)].r-tree[ls(i)].l+1;
    ll len_r=tree[rs(i)].r-tree[rs(i)].l+1;
    if(tree[i].add!=0){
        tree[ls(i)].add+=tree[i].add;
        tree[ls(i)].data+=tree[i].add*len_l;
        tree[ls(i)].mx+=tree[i].add;
        tree[rs(i)].add+=tree[i].add;
        tree[rs(i)].data+=tree[i].add*len_r;
        tree[rs(i)].mx+=tree[i].add;
        tree[i].add=0;
    }
    return;
}
void r_add(ll i,ll l,ll r,ll val){
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].data+=val*(tree[i].r-tree[i].l+1);
        tree[i].mx+=val;
        tree[i].add+=val;
        return;
    }
    pushdown(i);
    if(tree[ls(i)].r>=l)
        r_add(ls(i),l,r,val);
    if(tree[rs(i)].l<=r)
        r_add(rs(i),l,r,val);
    pushup(i);
    return;
}
ll r_max(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].mx;
    if(tree[i].r<l||tree[i].l>r)
        return LLONG_MIN;
    pushdown(i);
    ll ans=max(r_max(ls(i),l,r),r_max(rs(i),l,r));
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>m>>mod;
    build(1,1,N-5);
    for(ll i=1;i<=m;i++){
        char op;
        ll num;
        cin>>op>>num;
        if(op=='A'){
            num+=t;
            num%=mod;
            len++;
            r_add(1,len,len,num);
        }
        else{
            lstans=r_max(1,len-num+1,len);
            t=lstans;
            cout<<lstans<<endl;
        }
    }
    return 0;
}