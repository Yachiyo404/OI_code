#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,v;

signed main(){
    scanf("%lld%lld",&v,&n);
    vector <int> weight(n+1);
    vector <int> value(n+1);
    vector <int> dp(v+1,0);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&weight[i],&value[i]);
    for(int i=1;i<=n;i++){
        for(int j=weight[i];j<=v;j++){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    printf("%lld",dp[v]);
    return 0;
}