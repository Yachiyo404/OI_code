#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=-1;
ll e[210],dp[210][210];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>e[i];
        e[i+n]=e[i];
    }
    for(ll i=2;i<2*n;i++){
        for(ll j=i-1;i-j<n&&j>=1;j--){
            for(ll k=j;k<i;k++){
                dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+e[j]*e[k+1]*e[i+1]);
                ans=max(ans,dp[j][i]);
            }
        }
    }
    cout<<ans;
    return 0;
}