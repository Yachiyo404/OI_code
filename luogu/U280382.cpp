#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v,n;
ll s[105];
struct o{
    ll val,m;
}obj[105];
vector<ll>item_v;
vector<ll>item_m;
void divide(){
    for(ll i=1;i<=n;i++){
        ll cnt=s[i];
        for(ll k=1;k<=cnt;k*=2){
            item_v.push_back(k*obj[i].val);
            item_m.push_back(k*obj[i].m);
            cnt-=k;
        }
        if(cnt>0){
            item_v.push_back(cnt*obj[i].val);
            item_m.push_back(cnt*obj[i].m);
        }
    }
}
int main(){
    scanf("%lld%lld",&n,&v);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld%lld",&obj[i].val,&obj[i].m,&s[i]);
    divide();
    vector<ll>dp(v+1,0);
    for(ll i=0;i<item_m.size();i++){
        for(ll j=v;j>=item_m[i];j--)
            dp[j]=max(dp[j],dp[j-item_m[i]]+item_v[i]);
    }
    printf("%lld",dp[v]);
    return 0;
}