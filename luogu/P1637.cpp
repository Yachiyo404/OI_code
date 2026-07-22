#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll cmax=310000;
ll sqt[cmax];
ll a[cmax],a1[cmax];
ll m,ans;
ll l[cmax],r[cmax];
inline ll lowbit(ll x){
    return x&-x;
}
inline void add(ll x,ll val){
    while(x<=cmax){
        sqt[x]+=val;
        x+=lowbit(x);
    }
}
inline ll query(ll x){
    ll ans=0;
    while(x>0){
        ans+=sqt[x];
        x-=lowbit(x);
    }
    return ans;
}
inline ll q(ll val){
    return lower_bound(a1+1,a1+1+m,val)-a1;
}
int main(){
    ll n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a1[i]=a[i];
    }
    stable_sort(a1+1,a1+1+n);
    m=unique(a1+1,a1+1+n)-(a1+1);
    for(i=1;i<=n;i++){
        add(q(a[i]),1);
        l[i]=query(q(a[i])-1);
    }
    memset(sqt,0,sizeof(sqt));
    for(i=n;i>=1;i--){
        add(q(a[i]),1);
        r[i]=n-i-(query(q(a[i]))-1);
    }
    for(i=2;i<n;i++)
        ans+=l[i]*r[i];
    printf("%lld",ans);
    return 0;
}