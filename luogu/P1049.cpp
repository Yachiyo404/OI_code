#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v,n;
ll dp[1005][1005],obj_v[40];
int main(){
    scanf("%lld%lld",&v,&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&obj_v[i]);
    for(ll i=1;i<=n;i++){
        for(ll j=v;j>=0;j--){
            if(j>=obj_v[i])
                dp[i][j]=max(dp[i-1][j-obj_v[i]]+obj_v[i],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    printf("%lld",v-dp[n][v]);
    return 0;
}