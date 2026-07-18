#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll v[65][3],p[65][3],dp[32005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(!c){
            v[i][0]=a;
            p[i][0]=b;
        }
        else{
            if(!v[c][1]){
                v[c][1]=a;
                p[c][1]=b;
            }
            else{
                v[c][2]=a;
                p[c][2]=b;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=n;j>=0;j--){
            if(j>=v[i][0])
                dp[j]=max(dp[j],dp[j-v[i][0]]+v[i][0]*p[i][0]);
            if(j>=v[i][0]+v[i][1])
                dp[j]=max(dp[j],dp[j-v[i][0]-v[i][1]]+v[i][0]*p[i][0]+v[i][1]*p[i][1]);
            if(j>=v[i][0]+v[i][2])
                dp[j]=max(dp[j],dp[j-v[i][0]-v[i][2]]+v[i][0]*p[i][0]+v[i][2]*p[i][2]);
            if(j>=v[i][0]+v[i][1]+v[i][2])
                dp[j]=max(dp[j],dp[j-v[i][0]-v[i][1]-v[i][2]]+v[i][0]*p[i][0]+v[i][1]*p[i][1]+v[i][2]*p[i][2]);
        }
    }
    cout<<dp[n];
    return 0;
}