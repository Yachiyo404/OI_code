#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[105],w[105],m[105],dp[40005];
signed main()
{
	int n,W;
    cin>>n>>W;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>w[i]>>m[i];
		for(int j=1;j<=m[i];j++)
			for(int k=W;k>=j*w[i];k--)
				dp[k]=max(dp[k],dp[k-w[i]]+v[i]);
	}
    cout<<dp[W];
    return 0;
}
