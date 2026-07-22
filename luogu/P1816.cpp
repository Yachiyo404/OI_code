#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,m;
ll a[N],b[N];
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll len=(ll)sqrt(n)+1,cnt=(n+len-1)/len;
    for(ll i=1;i<=cnt;i++){
        ll ans=1e9;
        for(ll j=(i-1)*len+1;j<=i*len&&j<=n;j++)
            ans=min(ans,a[j]);
        b[i]=ans;
    }
    while(m--){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll k1=(l+len-1)/len,k2=r/len;
        ll ans=1e9;
        if(r-l<=len){
            for(ll i=l;i<=r;i++)
                    ans=min(ans,a[i]);
            printf("%lld ",ans);
            continue;
        }
        for(ll i=k1+1;i<=k2;i++)
            ans=min(ans,b[i]);
        for(ll i=l;i<=k1*len;i++)
            ans=min(ans,a[i]);
        for(ll i=k2*len+1;i<=r;i++)
            ans=min(ans,a[i]);
        printf("%lld ",ans);
    }
    return 0;
}
