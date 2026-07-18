#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n;
ll a[N],low[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++) 
        cin>>a[i];
    ll len=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=len,pos=len+1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(low[mid]>=a[i]){
                pos=mid;
                r=mid-1;
            } 
            else 
                l=mid+1;
        }
        if(pos==len+1){
            len++;
            low[len]=a[i];
        }
        else
            low[pos]=a[i];
    }
    cout<<len<<'\n';
    return 0;
}