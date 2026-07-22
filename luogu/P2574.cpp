#include<bits/stdc++.h>
#define ll long long
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e5+10;
ll n,m;
ll num[N];
char ch;
struct node{
    ll l,r;
    ll sum;

}tree[N<<2];
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
inline void pushup(ll i){
    tree[i].sum=tree[ls].sum+tree[rs].sum;
    return;
}
inline void pushdown(ll i){
    
}
int main(){
    n=read();m=read();
    for(ll i=1;i<=n;i++){
        cin>>ch;
        num[i]=ch-'0';
    }
    while(m--){
        ll op,l,r;
        op=read();l=read();r=read();
        if(op==0){
            
        }
        else{
            
        }
    }
    return 0;
}