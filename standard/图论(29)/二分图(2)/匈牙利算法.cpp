#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,e;
int ans[505];
bool vis[505];
vector<int>tu[505];
bool dfs(int x)
{
	for(int i:tu[x])
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(!ans[i]||dfs(ans[i]))
			{
				ans[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
signed main()
{
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			sum++;
	}
	cout<<sum;
	return 0;
}
