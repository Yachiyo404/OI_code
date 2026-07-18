#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll T;
set<pair<ll,ll>> s1,s2;
pair<ll,ll> add(ll x,ll *arr){
    ll addf=0,addg=0;
    ll h=arr[x];
    auto it=s1.lower_bound({x+1,LLONG_MIN});
    it--;
    if(it->second<=h){

    }
    


    return {addf,addg};
}
int main(){
    ios::sync_with_stdio(0);
    //freopen("rain.in","r",stdin);
    //freopen("rain.out","w",stdout);
    cin>>T;
    while(T--){
        ll n,q;
        ll a[N]={};
        ll suma=0,sumf=0,sumg=0;
        s1.clear();
        s2.clear();
        cin>>n;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        ll mx1=INT_MIN,mx2=INT_MIN;
        for(ll i=1;i<=n;i++){
            if(a[i]>mx1){
                mx1=max(mx1,a[i]);
                s1.insert(i,mx1);
            }
            suma+=a[i];
            sumf+=mx1;
        }
        for(ll i=n;i>=1;i--){
            if(a[i]>mx2){
                mx2=max(mx2,a[i]);
                s2.insert(n-i+1,mx2);
            }
            sumg+=mx2;
        }
        s1.insert(n+1,LLONG_MAX);
        s2.insert(n+1,LLONG_MIN);
        cin>>q;
        while(q--){
            ll x,v;
            cin>>x>>v;
            a[x]+=v;
            mx1=max(mx1,a[x]);
            auto ans=add(x,a);
            suma+=v;
            sumf+=ans.first;
            sumg+=ans.second;
            cout<<sumf+sumg-n*mx1-suma<<endl;
        }
    }
    return 0;
}