#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;
int n;
ll a[N];
ll ans=-1;
bool check(ll m){
    ll mi[N]={},mx[N]={};
    mi[1]=mx[1]=a[1];
    for(int i=2;i<=n;i++){
        mi[i]=min(a[i],a[1]-mi[i-1]);
        mx[i]=max(0ll,a[1]+a[i-1]-mx[i-1]+a[i]-m);
    }
    if(mi[n])
        return 0;
    else
        return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    ll l=1,r=3e5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l=max(l,a[i]);
    }
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}