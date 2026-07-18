#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e6+5;
int val[N],fa[N],dp[N][2],mk;
bool vis[N];
vector<int>tu[N];
void dfs(int x)
{
	dp[x][0]=0;
	dp[x][1]=val[x];
	vis[x]=1;
	for(int i:tu[x])
	{
		if(i==mk)
			continue;
		dfs(i);
		dp[x][1]+=dp[i][0];
		dp[x][0]+=max(dp[i][0],dp[i][1]);
	}
	return ;
}
int ck(int x)
{
	vis[x]=1;
	int f=fa[x];
	if(vis[f])
		return f;
	return ck(f);
}
int solve(int x)
{
	int sum=0;
	mk=ck(x);
	dfs(mk);
	sum=max(sum,dp[mk][0]);
	mk=fa[mk];
	dfs(mk);
	sum=max(sum,dp[mk][0]);
	return sum;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int d;
		cin>>val[i]>>d;
		tu[d].push_back(i);
		fa[i]=d;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			ans+=solve(i);
	cout<<ans;
	return 0;
}
