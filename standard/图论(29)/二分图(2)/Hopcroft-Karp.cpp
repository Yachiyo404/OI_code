#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e2+5;
int n,m,e;
int dx[N],dy[N],ans[N];
bool vis[N];
vector<int>tu[N];
bool dfs(int x)
{
	for(int i:tu[x])
	{
		if(dy[i]!=dx[x]+1)
			continue;
		dy[i]=-1;
		if(!ans[i]||dfs(ans[i]))
		{
			vis[x]=1;
			ans[i]=x;
			return 1;
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
	while(1)
	{
		queue<int>q;
		for(int i=1;i<=n;i++)
			dx[i]=-1;
		for(int i=1;i<=m;i++)
			dy[i]=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				dx[i]=0;
				q.push(i);
			}
		int dt=INT_MAX;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(dx[x]>dt)
				break;
			for(int i:tu[x])
			{
				if(dy[i]!=-1)
					continue;
				dy[i]=dx[x]+1;
				if(!ans[i])
					dt=dy[i]+1;
				else
				{
					dx[ans[i]]=dy[i]+1;
					q.push(ans[i]);
				}
			}
		}
		if(dt==INT_MAX)
			break;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				sum+=dfs(i);
	}
	cout<<sum;
	return 0;
}
