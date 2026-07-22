#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,m;
ll dp[1005][1005];
struct m{
    ll v,t;
}med[1005];
int main(){
    scanf("%lld%lld",&t,&m);
    for(ll i=1;i<=m;i++)
        scanf("%lld%lld",&med[i].t,&med[i].v);
    for(ll i=1;i<=m;i++){
        for(ll j=t;j>=0;j--){
            if(j>=med[i].t)
                dp[i][j]=max(dp[i-1][j-med[i].t]+med[i].v,dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    printf("%lld",dp[m][t]);
    return 0;
}