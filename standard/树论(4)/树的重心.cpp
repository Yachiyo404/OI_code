#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e4+5;
int n,rt,ans,dp[N],sz[N],deep[N];
vector<int>tu[N];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(int i:tu[x])
	{
		if(i!=fa)
		{
			dfs(i,x);
			sz[x]+=sz[i];
			dp[x]=max(dp[x],sz[i]);
		}
	}
	dp[x]=max(dp[x],n-sz[x]);
	return ;
}
void dfss(int x,int fa)
{
	deep[x]=deep[fa]+1;
	for(int i:tu[x])
		if(i!=fa)
			dfss(i,x);
	return ;
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	dfs(1,0);
	dp[0]=INT_MAX;
	for(int i=1;i<=n;i++)
		if(dp[rt]>dp[i])
			rt=i;
	cout<<rt<<" ";
	dfss(rt,0);
	for(int i=1;i<=n;i++)
		ans+=deep[i];
	cout<<ans-n;
	return 0;
}
