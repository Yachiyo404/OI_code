#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans=INT_MAX;
int w[610],dp[610][610],sum[610];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        w[n+i]=w[i];
    }
    for(int i=1;i<=2*n;i++)
        sum[i]=sum[i-1]+w[i];
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            dp[l][r]=INT_MAX;
            for(int k=l;k<r;k++)
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
        }
    }
    for(int i=1;i<=n;i++)
        ans=min(ans,dp[i][n+i-1]);
    cout<<ans;
    return 0;
}