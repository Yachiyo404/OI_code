#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,k;
ll a[N];
bool check(ll x){
    ll cnt=0;
    int l=1,r=n;
    while(l<r){
        if(a[l]+a[r]<=x){
            cnt+=(r-l);
            l++;
        }
        else
            r--;
    }
    return cnt>=k;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=0,r=2e9,ans=r;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}