#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e7;
ll ans,n;
ll num[1005][1005],dp[1005][1005];
int main(){
    scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++)
			scanf("%lld",&num[i][j]);
	}
    dp[1][1]=num[1][1];
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=i;j++)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
    }
    for(ll i=1;i<=n;i++)
        ans=max(ans,dp[n][i]);
    cout<<ans;
    return 0;
}