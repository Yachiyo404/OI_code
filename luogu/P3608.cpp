#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,l,r,cnt;
ll bit[N];
struct node{
    ll num,high;
}cow[N];
bool cmp(node a,node b){
    return a.high>b.high;
}
inline ll lowbit(ll x){
    return x&-x;
}
inline void add(ll x,ll y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }
}
inline ll ask(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&cow[i].high);
        cow[i].num=i;
    }
    stable_sort(cow+1,cow+n+1,cmp);
    for(ll i=1;i<=n;i++){
        add(cow[i].num,1);
        l=ask(cow[i].num-1);
        r=i-l-1;
        if(max(l,r)>2*min(l,r))
            cnt++;
    }
    printf("%lld",cnt);
    return 0;
}