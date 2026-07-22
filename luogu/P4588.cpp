#include<bits/stdc++.h>
#define ll long long
#define lc(i) i<<1
#define rc(i) i<<1|1
using namespace std;
const int N=5e5+10;
ll n,t,q,MOD,op,pos,m,j;
ll num[N];
struct node{
    ll l,r;
    ll data;
}tree[N<<2];
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
inline void count(ll i){
    tree[i].data=((tree[lc(i)].data%MOD)*(tree[rc(i)].data%MOD))%MOD;
}
inline void build(ll i,ll l,ll r){
    tree[i].l=l;
    tree[i].r=r;
    if(tree[i].l==tree[i].r){
        tree[i].data=1;
        return;
    }
    ll mid=(l+r)>>1;
    build(lc(i),l,mid);
    build(rc(i),mid+1,r);
    count(i);
}
inline void p_mul(ll i,ll pos,ll k){
    if(tree[i].l==tree[i].r){
        tree[i].data=k;
        tree[i].data%=MOD;
        return;
    }
    ll mid=(tree[i].l+tree[i].r)>>1;
    if(pos<=mid)
        p_mul(lc(i),pos,k);
    else
        p_mul(rc(i),pos,k);
    count(i);
}
int main(){
    t=read();
    while(t--){
        q=read();MOD=read();
        build(1,1,q);
        j=0;
        while(q--){
            op=read();
            if(op==1){
                j++;
                m=read();
                p_mul(1,j,m);
                printf("%lld\n",tree[1].data%MOD);
            }
            else{
                j++;
                pos=read();
                p_mul(1,j,1);
                p_mul(1,pos,1);
                printf("%lld\n",tree[1].data%MOD);
            }
        }
    }
    return 0;
}