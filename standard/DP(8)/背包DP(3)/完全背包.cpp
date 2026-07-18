#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[10005],t[10005],dp[10000005];
signed main()
{
	int T,m;
    cin>>T>>m;
    for(int i=1;i<=m;i++)
    	cin>>t[i]>>v[i];
    for(int i=1;i<=m;i++)
        for(int j=t[i];j<=T;j++)
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
    cout<<dp[T];
    return 0;
}
