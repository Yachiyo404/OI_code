#include<bits/stdc++.h>
#define int long long
using namespace std;
int r[6005],dp[6005][2];
bool vis[6005];
vector<int>tu[6005];
void dfs(int x)
{
	dp[x][0]=0;
	dp[x][1]=r[x];
	for(int i:tu[x])
	{
		dfs(i);
		dp[x][0]+=max(dp[i][1],dp[i][0]);
		dp[x][1]+=dp[i][0];
	}
	return ;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[v].push_back(u);
		vis[u]=1;
	}
	int sb;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			sb=i;
			break;
		}
	dfs(sb);
	cout<<max(dp[sb][0],dp[sb][1]);
	return 0;
}
