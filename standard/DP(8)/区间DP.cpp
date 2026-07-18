#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[205],dp[205][205];
signed main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=2*n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
			{
				int sum=dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];
                dp[i][j]=max(dp[i][j],sum);
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][i+n-1]);
	cout<<ans;
	return 0;
}
