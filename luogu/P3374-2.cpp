#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll num[N];
struct node{
    ll l,r;
    ll data;
}tree[N*4];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    if(l==r){
        tree[i].data=num[l];
        return;
    }
    ll mid=(r+l)/2;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    tree[i].data=tree[2*i].data+tree[2*i+1].data;
    return;
}
ll ask(ll i,ll l,ll r){
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].data;
    if(tree[i].r<l||tree[i].l>r)
        return 0;
    ll sum=0;
    if(tree[2*i].r>=l)
        sum+=ask(2*i,l,r);
    if(tree[2*i+1].l<=r)
        sum+=ask(2*i+1,l,r);
    return sum;
}
void add(ll i,ll x,ll k){
    if(tree[i].l==tree[i].r){
        tree[i].data+=k;
        return;
    }
    if(x<=tree[2*i].r)
        add(2*i,x,k);
    else
        add(2*i+1,x,k);
    tree[i].data=tree[2*i].data+tree[2*i+1].data;
    return;
}
int main(){
    n=read();m=read();
    for(ll i=1;i<=n;i++)
        num[i]=read();
    build(1,1,n);
    while(m--){
        ll op,x,y,k;
        op=read();
        if(op==1){
            x=read();k=read();
            add(1,x,k);
        }
        else{
            x=read();y=read();
            printf("%lld\n",ask(1,x,y));
        }
    }
    return 0;
}